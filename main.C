#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) <= (b)) ? (a) : (b)) 

int demogorgon(int dano[],int mana[],int n,int hp){
	int ans;
	if (hp <= 0) ans = 0;

	else if(n < 0) ans = 10000;

	else{

	ans = min(mana[n] + demogorgon(dano,mana,n-1,hp-dano[n]),demogorgon(dano,mana,n-1,hp));

	}

	return ans;

}


int main(){
	int hp,feiticos,ans,i;
	int dano[feiticos],mana[feiticos];

	while(scanf("%d %d",&feiticos,&hp) != -1){
	
		for(i = 0;i<feiticos;i++){
			scanf("%d %d",&dano[i],&mana[i]);
		}

		ans = demogorgon(dano,mana,feiticos-1,hp);

		if(ans == 10000) printf("-1\n");
		else printf("%d\n\n",ans);

	}
}