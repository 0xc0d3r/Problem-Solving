#include<stdio.h>
#include<string.h>
void caesar_cipher(char s[],int key,int enc_or_dec){
	int i,slen=strlen(s),ascii;
	if(enc_or_dec == 2)
		key = -key;
	for(i=0;i<slen;i++){
		if( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) ){
			ascii = s[i];
			ascii+=key;
			if(isupper(s[i])){
				if(ascii > 'Z') ascii -= 26;
				else if(ascii < 'A') ascii += 26;
			}
			else if(islower(s[i])){
				if(ascii > 'z') ascii -= 26;
				else if(ascii < 'a') ascii += 26;
			}
			s[i]=ascii;
		}
	}
}

void reverse_words_in_sentence(char s[]){
	char buf[16];
	int si,bi=0,slen = strlen(s),ri,i;
	for(si=0;si<=slen;si++){
		if(s[si] == ' ' || s[si] == '\0'){
			for(i=si-1,ri=0;ri<bi;ri++) 
				s[i--] = buf[ri];
			bi=0;
			continue;
		}
		buf[bi++] = s[si];
	}
}

int main(void) {
	char text[128],junk;
	int op;
	scanf("%d%c",&op,&junk);
	scanf("%[^\n]s",text);
	reverse_words_in_sentence(text);
	caesar_cipher(text,3,op);
	printf("%s", text);
	return 0;
}