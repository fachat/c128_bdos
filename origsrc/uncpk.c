
#include <stdio.h>
#include <strings.h>

FILE *fp,*fpo;
char name[100];
int i,c,n;
char *p;

int main(int argc, char *argv[]){
	if(argc==2){
		fp=fopen(argv[1],"rb");
		if(fp){
			if(fgetc(fp)==1){
			  do{
				/* read name */
				i=0;
				while(c=fgetc(fp)){
					if(c==EOF) break;
					name[i++]=c;
				}
				name[i] = 0;
				if(!c){
					printf("uncpk %s\n",name);
					while (p = index(name, '/')) {
						*p = '_';
					}
					fpo=fopen(name,"wb");
					if(fpo){
						while((c=fgetc(fp))!=EOF){
							if(c==0xf7){
								n=fgetc(fp);
								if(!n) {
									break;
								}
								c=fgetc(fp);
								if(n!=EOF && c!=EOF)
									while(n--)
										fputc(c,fpo);
							} else 
								fputc(c,fpo);
						}
						fclose(fpo);
					} else {
						fprintf(stderr,"Couldn't open output file %s !\n",name);
						c=EOF;
					}
				}
			  } while(c!=EOF);
			} else
				fprintf(stderr,"Wrong Version!\n");
		} else
			fprintf(stderr,"File %s not found!\n",argv[1]);
	} else 
		fprintf(stderr,"uncpk usage: uncpk file.cpk\n");
}
