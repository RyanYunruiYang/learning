/*
Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p. 388) in place of
the end_connection function.
*/

#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination*);
void disconnect(connection);

connection connect(destination*) {
    std::cout << "Connecting..." << std::endl;
    return connection(); // Return a new connection object
}

void disconnect(connection) {
    std::cout << "Disconnecting..." << std::endl;
}

// void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) { 
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *p){ disconnect(*p); });
}

int main() {
    destination d;
    f(d);
    return 0;
}