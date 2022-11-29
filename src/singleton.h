#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
   public:
      static T& getInstance()
      {
         static T instance;
         return instance;
/*
         if(m_instance == NULL)
         {
            m_instance = new T();
         }

         return m_instance;
*/
      }

      // Remove "copyconstructor" and "= operator"
      Singleton(Singleton const&) = delete;
      Singleton& operator=(Singleton const &) = delete;

   protected:
      Singleton() {}
      ~Singleton() {}
};

#endif