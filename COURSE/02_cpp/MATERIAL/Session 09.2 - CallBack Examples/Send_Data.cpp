#include<iostream>
#include<array>
#include<functional>
/*
Assignment : 

* Calculate takes  two parameters first is array/vector, second is a function which
* modifys the elements of the array:to be swapped with another array
* call std::sort for sorting array

*/
void CommStackOnEvent(std::function<void (bool&) > cbk);
void Send()
{
    auto send_data = []()->bool{ 
                    std::cout << "send data is called in commStack" << std::endl;
                    return true; };

    auto onEvent = [&send_data](bool & response){ 
        response = send_data();
        return true;};
        
   CommStackOnEvent(onEvent);
}

void Send2(std::function<bool (void)> send_data_cbk)
{
    auto onEvent = [&send_data_cbk](bool & response){ 
        response = send_data_cbk();
        return true;};

   CommStackOnEvent(onEvent);
}

void CommStackOnEvent(std::function<void (bool&) > cbk_onevent)
{
    //execution
    bool response = false;
    cbk_onevent(response); // Onevent
    if(response)
    {
        std::cout << "Handling request" <<std::endl;
    }
    else
    {
        std::cout << "Handling error" <<std::endl;
    }
}



int main() {

    // Send();

    auto send_data = []()->bool{ 
                    std::cout << "send data is called in commStack" << std::endl;
                    return false; };
    Send2(send_data);


   return 0;
}