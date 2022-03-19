#include <iostream>


class Event {
public:
 virtual std::string description() const { return ""; };
}; 

class Client
{
    public:

        virtual ~Client();

        virtual void processEvent(const Event& event)
        {
            std::cout << event.description();
        }
};

class Server
{
    private:

        std::vector<Client*> clients;

        Server(const Server&) = delete;
        Server& operator=(const Server&) = delete;
    public:

        void register(Client *c)
        {
            for (int i =0; i < clients.size(); i++)
            {
                if(clients[i] == c)
                {
                    return;
                }
            }
            clients.push_back(c);
        }

        void notify(const Event& event)
        {
            for (int i = 0; i < clients.size(); i++)
            {
                clients[i]->processEvent(event);
            }
        }
};

class NewMailEvent : public Event {
public:
 std::string description() const override;
 std::string sender() const;
 std::string subject() const;
}; 

class BadEvent : public std::exception {
public:
 BadEvent() {}
 const char* what() const override {
 return "Event not suitable for client";
 }
}; 

class MailClient : public Client{

    private:


    public:
        
        void processEvent(const Event& event) override
        {
             const NewMailEvent* ptr = dynamic_cast<const NewMailEvent*>(&event);
            
            if(!ptr)
            {
                throw BadEvent();
            }
            std::cout << event.subject();
        }      
};