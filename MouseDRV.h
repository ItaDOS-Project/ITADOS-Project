/// BIBLIOTECA DE FUNCOES DE I/O DO MOUSE PARA O ITADOS GRAPH POR ARUNI AMSTEL, COPYLEFT 2017
///* This Software was written by Aruni Amstel (bioaruni@gmail.com) & Bruno Dal Ponte in may, 2017.
///* This file use the GNU-GPL license available at https://www.gnu.org/licenses/gpl-2.0.txt
///* This library is the main mouse function for the operating system ITADOS
///* This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.

#include<windows.h>

class MouseInputHandler
{
      //mouse input handler callback function pointer
      typedef void (*MIHCB)(int,int,void*);

      public:
      MouseInputHandler(){}
      ~MouseInputHandler(){}
      void init();

      inline void start_polling()
      {
             _beginthread(polling_function,0,this);
             polling=true;
      }

      inline void stop_polling()
      {
             input.quit=true;
             while (polling);
      }

      int getx();
      int gety();
      void getxy(int & x, int & y);

      //setting the callbacks
      inline void set_lbdcb(MIHCB f){lbdcb=f;}
      inline void set_lbucb(MIHCB f){lbucb=f;}
      inline void set_lbccb(MIHCB f){lbccb=f;}
      inline void set_rbdcb(MIHCB f){}
      inline void set_rbucb(MIHCB f){}
      inline void set_rbccb(MIHCB f){}

      //setting the params for the callbacks
      inline void set_lbdcbp(void*p){lbdcbp=p;}
      inline void set_lbucbp(void*p){lbucbp=p;}
      inline void set_lbccbp(void*p){lbccbp=p;}
      inline void set_rbdcbp(void*p){}
      inline void set_rbucbp(void*p){}
      inline void set_rbccbp(void*p){}

      private:
      struct MouseInput
      {
             //current and previous mouse button status
             bool cleft, pleft;
             bool cright, pright;

             bool quit;
             int x,y;

      } input;

      bool polling;

      static void polling_function(void*);
      static inline bool is_pressed(int key)
      {
             return (GetAsyncKeyState(key)>>15);
      }

      MIHCB lbdcb;
      MIHCB lbucb;
      MIHCB lbccb;
      MIHCB rbdcb;
      MIHCB rbucb;
      MIHCB rbccb;

      void* lbdcbp;
      void* lbucbp;
      void* lbccbp;
      void* rbdcbp;
      void* rbucbp;
      void* rbccbp;

};



