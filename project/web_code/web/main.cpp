/**
 * @file main.cpp
 *
 * @copyright 2020 Amogh Bhagwat & csci3081 staff, All rights reserved.
 */
#include <iostream>

#include "src/config_manager.h"
#include "web_code/web/visualization_simulator.h"

#include "web_code/web/my_web_server_session_state.h"
#include "web_code/web/my_web_server_command.h"
#include "web_code/web/my_web_server_session.h"
#include "web_code/web/my_web_server.h"

// #define _USE_MATH_DEFINES
// #include <cmath>
// #include <libwebsockets.h>


int main(int argc, char**argv) {
  std::cout << "Usage: ./build/bin/ExampleServer 8081" << std::endl;
  if (argc > 1) {
    int port = std::atoi(argv[1]);
    MyWebServerSessionState state;

    MyWebServer* myWS = new MyWebServer();
    ConfigManager* cm = new ConfigManager();

    cm->ReadConfig("config.txt");
    std::cout << "Using default config file: config.txt" << std::endl;
    VisualizationSimulator* mySim =
    new VisualizationSimulator(myWS, cm);

    state.commands["getRoutes"] = new GetRoutesCommand(myWS);
    state.commands["getBusses"] = new GetBussesCommand(myWS);
    state.commands["start"] = new StartCommand(mySim);
    state.commands["update"] = new UpdateCommand(mySim);
    state.commands["initRoutes"] = new InitRoutesCommand(cm);
  // Will trigger the pause execute() fucntion when pressed.
    state.commands["pause"] = new PauseCommand(mySim);
  // Will trigger the AddBusListenerCommand execute() function when pressed.
    state.commands["listenBus"] = new AddBusListenerCommand(mySim);
  // Will trigger the AddStopListenerCommand execute() function when pressed.
    state.commands["listenStop"] = new AddStopListenerCommand(mySim);
  WebServerWithState<MyWebServerSession, MyWebServerSessionState>
    server(state, port);
    while (true) {
      server.service();
      }
  }
  return 0;
}
