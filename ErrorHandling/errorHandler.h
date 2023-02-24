#ifndef ERRHANDLER 
#define ERRHANDLER

#define return_(status) do{ return_status = status; goto return_label; }while(0)

typedef int Errno;

#endif