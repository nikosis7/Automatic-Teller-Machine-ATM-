#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct bill{                // orizoume mia nea domh
          int  count;    
          int  notes; 
   };          
   



int calc_of_possible_withdrawal_amount(struct bill *,int k,int c);
int search1(struct bill Bills[], int n, int k);
int search2(struct bill Bills[], int n, int k);



main()
{
    
      int i,k,choice,a,b,c; //k= arithmos eggrafwn tou arxeiou, choice = epilogh tou xrhsth, tool_code=o kwdikos proiontos
                                    //pou dinei o xrhsths, f=elegxos gia to ean yparxei mia eggtafi mesa ston pinaka
      FILE *fp1;                 // oi tesseris deiktes typou arxeiou. O prwtos gia na anoiksoume gia diabasma to arxeio "drivers.txt"
                                    // O deyteros gia na anoiskoume to arxeio "owners.txt" gia diabasma, O tritos gia na anoiksoume gia diabasma to arxeio "offenses.txt"
                                    // O deyteros gia na anoiskoume to arxeio "revokes.txt" gia diabasma
     
      char filename[30];    //ews 30 xaraktires to onoma tou arxeiou
    
      printf("Give file name to read types and number of bills to fill the ATM: \n"); //zhtame ena arxeio gia na anoiksoume
	  scanf("%s",filename);
      fp1=fopen(filename,"r"); //anoigoume to arxeio gia na to xrhsimopoihsoume
     
      
      if(fp1==NULL) //eksetazei an exei anoiksei to arxeio
           printf("Cannot open file \n");
     
      // Metafora twn arxeiwn stous pinakes
      rewind(fp1);
      fscanf(fp1,"%d",&k);
      
      struct bill *Bills;                 // Drivers = Pinakas eggrafwn me stoixeia odigwn
      Bills = (struct bill *)malloc(k*sizeof(struct bill)); 
      for (i=0;i<k;i++)
             fscanf(fp1,"%d %d\n",&Bills[i].count,&Bills[i].notes);
      
	  
      do
      {
         printf("Give the amount to withdraw: \n");
         scanf("%d",&c);      
         choice=calc_of_possible_withdrawal_amount(Bills,k,c);
      
     

       
      
      
     
      }while (choice!=-1);
      fclose(fp1);
      free(Bills); 
      
      system("pause");
      }
      
      
     
     
int calc_of_possible_withdrawal_amount(struct bill Bills[],int k,int c){
     int i,j,s,a,p=0,d,q=0,g=0,y=0,m=0,htc,z=0,n,choise;
     s=0;
     for (i=0; i<k; i++){
             s=s+(Bills[i].count*Bills[i].notes);
     }
     if (s>0){
         if (c>s) //se periptwsi pou zhthsei perissotera apo oti exei to atm
             {
             printf("The biggest amount of money you can get is: %d\n", s);
                     
             }
         else if (c==s) //se periptwsi pou zhthsei osa exei to atm
             {
                 printf("Bills withdraw: ");
                 for (i=0; i<k; i++){  //emfanizei ola ta xrhmata pou tha parei kai mhdenizei to atm
                    printf("%dx%d  ", Bills[i].count, Bills[i].notes);
                    Bills[i].count=0;
                    Bills[i].notes=0;
                }
             }
                 
         else
             {
             a=c; //orizoume mia metablhth a ish me ta xrhmata pou zhthse 
             htc=1;
             while (c>=5 && htc!=0){ //to c<5 to vazoume giati den dinei ligotera apo 5 euro
                 n=200;
                 a=a/n; //eksetazoume posa xartonomismata tou n(stin periptwsi mas twn 200 euro xreizontai
                 if (c>=n){
                          p=search1(Bills,n,k); //psaxnei posa xartonomismata apo to ekastote n yparxoun
                          if (a>=p){ //an ta xartonomismata pou xreiazomaste einai perissotera apo auta pou yparxoun
                                    
                           c=c-(p*n); //meiwnei to poso pou ypoleipetai
                           a=c; 
                           d=search2(Bills,n,k); //psaxnei se poia thesi tou arxeiou einai to n (stin periptwsi mas twra ta xartonosmata twn 200)
                           Bills[d].count-=p; //meiwnei ta xrhmata pou yparxoun sto atm
                          }
                           else{
                             c=c-a*n; //an ta xartonomismata pou xreiazomaste einai ligotera apo auta pou yparxoun sto atm
                             d=search2(Bills,n,k);
                             Bills[d].count-=a; //meiwnei ta xartonomismata kata a, diladi afairei auta pou xreiazetai
                             p=a; 
                             a=c;
                              }  
                              if (c<5){
                                        htc=0;
                                        }
                               
                                
                                
                             
                 }
                 n=100; //allazoyme to n kathe fora pou teleiwnei i diadikasia gia kapoio xartonomisma
                 
                 
                 if (c>=n && htc!=0){
                          a=a/n;
                          q=search1(Bills,n,k);
                          if (a>=q){
                                    
                           c=c-(q*n);
                           a=c;
                           d=search2(Bills,n,k);
                           Bills[d].count-=q;
                           }
                           else{
                             c=c-a*n;
                             d=search2(Bills,n,k);
                             Bills[d].count-=a;
                             q=a;
                             a=c;
                             
                             } 
                             if (c<5){
                                        htc=0;
                                        }  
                                
                                
                             
                 }
                 n=50;
                 
                 
                 if (c>=n && htc!=0){
                          a=a/n;
                          g=search1(Bills,n,k);
                          if (a>=g){
                                    
                           c=c-(g*n);
                           a=c;
                           d=search2(Bills,n,k);
                           Bills[d].count-=g;
                           
                           }
                           else{
                             c=c-a*n;
                             d=search2(Bills,n,k);
                             Bills[d].count-=a;
                             g=a;
                             a=c;
                             
                             } 
                             if (c<5){
                                        htc=0;
                                        }  
                                
                                
                             
                 }
                 n=20;
                 
                 
                 if (c>=n && htc!=0){
                          a=a/n;
                          y=search1(Bills,n,k);
                          if (a>=y){
                                    
                           c=c-(y*n);
                           a=c;
                           d=search2(Bills,n,k);
                           Bills[d].count-=y;
                           
                           }
                           else{
                             c=c-a*n;
                             d=search2(Bills,n,k);
                             Bills[d].count-=a;
                             y=a;
                             a=c;
                             
                             }  
                             if (c<5){
                                        htc=0;
                                        }  
                             
                 }
                 n=10;
                               
             
                 if (c>=n && htc!=0){
                          a=a/n;
                          m=search1(Bills,n,k);
                          if (a>=m){   
                           c=c-(m*n);
                           a=c;
                           d=search2(Bills,n,k);
                           Bills[d].count-=m;
                           
                           }
                           else{
                             c=c-a*n;
                             d=search2(Bills,n,k);
                             Bills[d].count-=a;
                             m=a;
                             a=c;
                             
                             }   
                             if (c<5){
                                        htc=0;
                                        }
                               
                 }
                 n=5;
                  
                 
                 
                 if (c>=n && htc!=0){
                          a=a/n;
                          z=search1(Bills,n,k);
                          
                          
                          if (a>=z){
                                    
                           c=c-(z*n);
                           a=c;
                           d=search2(Bills,n,k);
                           Bills[d].count-=z;
                           
                           }
                           else{
                            
                             c=c-a*n;
                             d=search2(Bills,n,k);
                            
                             Bills[d].count-=a;
                             z=a;
                             a=c;
                              
                             }  
                           
                                        htc=0;
                                        
                                  
                 }
                 
             }
             printf("Bills withdrawn: 200x%d 100x%d 50x%d 20x%d 10x%d 5x%d", p, q, g, y, m, z);    
                 
                 
                 
                 
             }
             printf("\n");
        return 0;
    }
    else{ //ean den meinoun xrhmata sto atm
    //to mhnyma emfanizetai otan zhthsei o epomenos xrhmata oxi otan o teleutaios travhksei osa exei
        printf("No bills left in the machine.\n"); 
        return -1;
        }
}




                 
int search1(struct bill Bills[], int n, int k){ //epistrefei posa xartonomismata n( diladi 200,100 klp) yparxoyn sto atm 
    int i,s=0;
    for (i=0;i<k;i++){
        if (Bills[i].notes==n){
                               s=Bills[i].count;
                               return s;
        }
    }
}
    
                        
int search2(struct bill Bills[], int n, int k){ //epistrefei ti thesi pou yparxei to xartonomisma pou zhtame, ston pinaka
    int i;
    for (i=0;i<k;i++){
        if (Bills[i].notes==n){
                               return i;
        }
    }
}
        
    
             
   
   
   
   

      

            
      
      
      
      
      
      
      
      
            
           
                        
