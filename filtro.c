#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>
#include <linux/tcp.h>

#include <linux/fs.h>
#include <asm/uaccess.h>

static struct nf_hook_ops nfho;         //struct holding set of hook function options
struct teste{
  int codigo;
  int idade;
};

struct teste *a;

//function to be called by hook
unsigned int hook_func(unsigned int hooknum, struct sk_buff **skb, const struct net_device *in, const struct net_device *out, int (*okfn)(struct sk_buff *))
{
  struct iphdr *ip_header = (struct iphdr *)skb_network_header(skb);
  struct tcphdr *tcp_header=NULL;
  __u32 src_ip = (unsigned int)ip_header->saddr;
  __u16 destino;
  unsigned int a,b,c,d;
  a=src_ip & 0x000000FF;
  b=(src_ip & 0x0000FF00)>>8;
  c=(src_ip & 0x00FF0000)>>16;
  d=(src_ip & 0xFF000000)>>24;
//  a=a>>28;
  unsigned int dest_ip = (unsigned int)ip_header->daddr;
  destino=0;
  if(ip_header->protocol==IPPROTO_TCP){
    tcp_header = (struct tcphdr*)skb_transport_header(skb);
    destino= (unsigned short int)(tcp_header->source<<8)+(tcp_header->source>>8);
  }
  printk(KERN_INFO "packet %u.%u.%u.%u\n", a,b,c,d); // /var/log/messages
  printk(KERN_INFO "porta: %hu" ,destino);
  if(destino==1234)
    return NF_DROP;   //recusa o pacote
  else
    return NF_ACCEPT; //Aceita o pacote
}

//Called when module loaded using 'insmod'
int init_module()
{

  create(&lista_regras);
  struct file *f;
  char buff[100];
  char instrucao[100];
  mm_segment_t fs;
  int i=0, count=0, sair=0;
  f= filp_open("regras.txt", O_RDONLY,0);
  if(f==NULL)
    printk(KERN_INFO "Erro na abertura do arquivo");
  else{
    fs=get_fs(); //Guarda o limite do modo kernel
    set_fs(get_ds()); //get_ds() pega o limite infinito e set_fs(), coloca o limite infinito para que seja possivel acessar o espaço de usauário e ler o arquivo
    f->f_op->read(f, buff,1,&f->f_pos);
	instrucao[i] = buff[0];
	do
	{

		i++;
		/* read(ponteiro de arq, buffer para guardar o q foi lido, quantos caracteres ler, posicao atual de leitura) não tenho certeza*/
		f->f_op->read(f, buff,1,&f->f_pos);
		instrucao[i] = buff[0];
		//Achou uma regra
		if(buff[0]== ';')
		{
			count++;
			//Marca o fim da string (fim da regra)
			instrucao[i+1]='\0';
			//Verifica se já chegou na marca end; que indica fim do arquivo
			if(strcmp(instrucao,"end;")==0)
			{
				//chave ativada para sair do laço
				sair=1;
				continue;
			}
			printk(KERN_INFO "Regra %d: %s\n",count ,instrucao);
			insert(&lista_regras, instrucao);
			i=0;
			f->f_op->read(f, buff,1,&f->f_pos);
			f->f_op->read(f, buff,1,&f->f_pos);
			instrucao[i] = buff[0];

		}

	}while(sair==0);

	set_fs(fs); //Volta ao espaço de kernel normal, que foi guardado anteriormente.
	filp_close(f, NULL);
  nfho.hook = hook_func;
  nfho.hooknum = NF_INET_PRE_ROUTING;
  nfho.pf = PF_INET;
  nfho.priority = NF_IP_PRI_FIRST;
  nf_register_hook(&nfho);

  return 0;
 }
 return 1;
}

//Called when module unloaded using 'rmmod'
void cleanup_module()
{
  nf_unregister_hook(&nfho);                     //cleanup – unregister hook
}
