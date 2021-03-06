/*
 * Program to calculate SHA 256-bit hash of an input. Taken from bradconte.com/sha256_c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sha256.c"

/*
 * Output should be:
 * 49454bcda10e0dd4543cfa39da9615a19950570129420f956352a58780550839
 */

void print_hash(unsigned char hash[])
{
   int idx;
  
   for (idx=0; idx < 32; idx++)
      printf("%x",hash[idx]);
  
   printf("\n");
}

int main()
{
   unsigned char text[] = "497";
                 
   unsigned char *hash = (unsigned char *) malloc(32);  // 32 bytes = 256 bits           
   int idx;
   SHA256_CTX ctx;

   // Hashing procedure 
   sha256_init(&ctx); // Init
   sha256_update(&ctx, text, strlen(text)); // Update
   sha256_final(&ctx, hash); // Final
   print_hash(hash); // Print 256-bit HASH

   return 0;
}


