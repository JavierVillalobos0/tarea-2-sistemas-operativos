#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
int leer (int * argc, char *argv[]){
   FILE *fp = fopen( argv[1], "r");
    char line[11];
        
    if (fp == NULL)
    {
        std::cout << "File opening Unsuccessful\n";
        exit(1);
    }
    
    while (fgets(line , 11 , fp) != NULL)
    {
        std::string t = "ping " + (std::string ) line + "\n";
        system((t).c_str());
        //printf("%s",line);
        
    }
   fclose(fp) ;
   pthread_exit(0);

  return 0;
}

int main(int argc, char *argv[])
{
  pthread_t threads[argc - 1];
  int i = 0;

  /* Crea todos los hilos */
  for (i=0; i < argc - 1; i++) {
    pthread_create(&threads[i], NULL, leer, argv[i+1]);
  }

  /* Para esperar por el término de todos los hilos */
  for (i=0; i< argc - 1; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
    
 }
