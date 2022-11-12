#include <iostream>
#include <memory>

template <typename T>
class UniquePtr {
    private:
        T* ptr;
        int count_copy;
    public:
        UniquePtr(T *ptr)
        {
            this->ptr = ptr;
            count_copy=0;
        }

        UniquePtr()
        {
            this->ptr = nullptr;
            count_copy=0;
        }

	    UniquePtr (const UniquePtr&obj)
	    {
		    ptr=obj.ptr;
		    count_copy++;
	    }

	    UniquePtr operator=(const UniquePtr&obj)
	    {
		    ptr=obj.ptr;
		    count_copy++;
		    return *this;
	    }

        T& operator*  () const
        {
            return *ptr;
        }

        T* operator-> () const
        {
            return ptr;
        }

        ~UniquePtr(){
            if(ptr!=NULL&&count_copy==0)
            {
                delete ptr;
            }
            else
            {
                count_copy--;
            }
        }
};


int main(){

    return 0;
}
