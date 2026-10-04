#include <httplib.h>
#include <iostream>
#include "docgianguoilon_routes.h"
using namespace std;

int main() {
    httplib::Server svr;            // create svr obj from Server class from httplib library
    
    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res){
        res.set_content("pong", "text/plain");
    });

    RegisterDocGiaNguoiLonRoutes(svr);

    cout << "Server listening on http://localhost:8080\n";

    svr.listen("0.0.0.0", 8080);

    return 0;
}


