#include <stdio.h>
#include <stdlib.h>

void p(int pilani,int n){
	printf("Pilani: %u\n",(uint)&pilani);
	p(pilani,n+1);
}
void g(int goa){
	printf("Goa: %u\n",(uint)&goa);
}
void h(int hyd){
	printf("Hyderabad: %u\n",(uint)&hyd);
}
void d(int dub){
	printf("Dubai: %u\n",(uint)&dub);
}
int main(){
	int pilani;
	int goa;
	int hyd;
	int dub;
	printf("Pilani: %u\n",(uint)&pilani);
	printf("Goa: %u\n",(uint)&goa);
	printf("Hyderabad: %u\n",(uint)&hyd);
	printf("Dubai: %u\n",(uint)&dub);
	p(pilani,0);
	g(goa);
	h(hyd);
	d(dub);
}
