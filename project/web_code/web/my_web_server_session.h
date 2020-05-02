/**
 * @file my_web_server_session.h
 *
 * @copyright 2020 3081 staff, All rights reserved.
 */
#ifndef WEB_MY_WEB_SERVER_SESSION_H_
#define WEB_MY_WEB_SERVER_SESSION_H_

#include "WebServer.h"
#include "web_code/web/my_web_server_session_state.h"


class MyWebServerSession : public JSONSession {
 public:
        explicit MyWebServerSession(MyWebServerSessionState s) : state(s) {}
        ~MyWebServerSession() {}

        void receiveJSON(picojson::value& val) override;
        void update() override {}

 private:
        MyWebServerSessionState state;
};


#endif  // WEB_MY_WEB_SERVER_SESSION_H_
