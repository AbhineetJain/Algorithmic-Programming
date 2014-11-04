#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/* Head ends here */
void quickSort(int ar_size, int *ar){
   int p, i, j, k, l;
   int big[ar_size], small[ar_size];
   p=ar[0];
	for(j=1, k=0, l=0; j<ar_size; j++){
		if(ar[j]>p)
	        	big[k++]=ar[j];
	        else
	               small[l++]=ar[j];
        }
   int b_size=k, s_size=l;
   if(s_size>=2)
	   quickSort(s_size, small);
   if(b_size>=2)
	   quickSort(b_size, big);
   for(i=0, k=0; k<s_size; k++, i++)
             ar[i]=small[k];
   ar[i++]=p;
   for(k=0; k<b_size; k++, i++)
             ar[i]=big[k];
}

/* Tail starts here */
int main(void) {
	   
	      int _ar_size;
	      scanf("%d", &_ar_size);
	      int _ar[_ar_size], _ar_i;
	      for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		         scanf("%d", &_ar[_ar_i]); 
	      }
	      quickSort(_ar_size, _ar);   
	      for(_ar_i=0; _ar_i<_ar_size; _ar_i++)
		      printf("%d ", _ar[_ar_i]);
	      printf("\n");
	      return 0;
}
