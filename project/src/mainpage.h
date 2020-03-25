/**
 * @file mainpage.h
 *
 * @copyright 2020 Amogh Bhagwat, All rights reserved.
 *
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage Start Guide
 *
 *
 * \section intro_sec Introduction
 *
 * Welcome to the bus simulator program.
 * The bus simulator works a lot like the
 * University of Minnesota's GopherTrip app.
 * This program lets you follow buses along
 * routes. The program also lets you know how
 * many people are on the bus and how many
 * people are on each stop. Read further to explore and
 * to get started with the bus simulator.
 *
 *
 * \section design_sec Design
 *
 * \subsection factory_design Factory Pattern
 *
 * In this project we implemented a Factory Pattern to help
 * us generate random passengers and different types of buses.
 * You might be wondering what is a Factory Pattern?
 * A factory pattern lets you create objects of different
 * types, similar to a real life factory where we create different types of
 * things. By using a factory we no longer need
 * to call the constructor of each new type. Instead we
 * can call the factory with a parameter to
 * create the desired object.
 * As an example, we can consider a pet factory, where
 * the base  class is a generic pet, from which, we make
 * inherited sub-classes such as dog and cat.
 * Inside the pet factory we create a method called generate and call it
 * with a desired pet type.
 *
 * There are two ways we can implement these Factory Patterns, either Concrete
 * or Abstract. In the next section we'll talk about pros and cons of each and
 * talk about what I implemented to create a bus factory.
 *
 * \subsection Concrete_design Concrete Factory Pattern
 * A Concrete Factory Pattern involves creating one Factory that lists all the
 * objects that are going to be implemented using the factory.
 * Below is a implementation of a concrete bus factory.
 *
 *
 * ![Concrete factory](@ref ConcreteBusFactory.png)
 *
 *
 *
 * Pro: The pro of using a concrete bus factory
 * is that it has small up front work as we only need to create one class
 * for the objects we want to create. This translates into second advantage
 * that concrete bus factories require less code than abstract ones.
 * Concrete factories also are open to extension.
 * if we look at the UML above, to extend to
 * a new bus type, all we would have to do
 * is create a new class for the new type and
 * add a line of code in the factory.
 *
 * Con: a concrete factory might seem better but it
 * does have some cons. One of which is performance.
 * For this program it really isn't a problem as we have only three types,
 * but if we had to implement several types,
 * the factory would take more time than a abstract design would.
 * The concrete design is also not that great for maintenance as new additions
 * may impact changes to  programs using the factory.
 *
 * \subsection Abstract_design Abstract Factory Pattern
 * An Abstract Factory Pattern is little different.
 * Instead of creating a single factory that includes creation of all object
 * types, we create only a generic object  template and then create
 * factory objects that concentrate only on creation of different types.
 * Below is the same bus class, but instead
 * this time we are implementing as an abstract design
 *
 *
 * Example Implementation
 * ![Abstract factory](@ref AbstractBusFactory.png)
 *
 *
 *
 * Pro: of using this is that it is very open to
 * extension as we would need to just create
 * the new subclass and it's factory. It is also
 * closed for modification. Abstract Factories
 * also have high cohesion and low coupling,
 * which is really helpful for bigger implementations.
 *
 * Con: of using this would be more work up front.
 * in the Abstract Factory Pattern we have to create
 * more classes as each object type needs its own factory.
 *
 *
 * \subsection what_i_choose What I implemented
 * I ended up choosing the concrete bus factory pattern
 * because i need only three object types and I don't think going forward we
 * will have to create more types of buses. It was easy to code and
 * implementation was simple.
 *
 * \section how_to_run Getting Started
 *
 * \subsection obtain_code How To Obtain The Sim
 * To obtain the code to run the sim we will have
 * to clone from my master branch. The link is
 * provided to
 * [my git repo.](https://github.umn.edu/umn-csci-3081-s20/repo-bhagw018.git)
 * After you have accessed my repo you will have
 * to clone it into your own machine.
 * I am providing another link showing how to clone a repo from
 * the people at github.
 * [How to clone a repo](https://help.github.com/en/github/creating-cloning-and
 *-archiving-repositories/cloning-a-repository)
 *
 * Side note: make sure you clone this repo on a cse machine as we will be
 * running the simulator on a cse machine.
 * Read next section on how to run the simulator.
 *
 * \subsection run_code How To Compile And Run Sim
 * Once you have obtained the code for the sim
 * you should vole or ssh login into a cse machine.
 * After you have done that go through the README file provided
 * at the bottom of the project folder.
 * It outlines steps to compile the program and
 * run the simulator. It also provides a guide
 * for running google style guide and google tests.
 *
 * \subsection classes_to_know Important Classes
 * The bus simulator has four important classes
 * Passenger, Stop, Route, and Bus.
 *
 * The Passenger class takes care of the people getting on/off the bus.
 * To further understand the methods click the highlighted Passenger.
 *
 * The Stop class creates individual stops that eventually become
 * part of a route. It also includes the Passenger class.
 * The location of the stops are determined by longitude and latitude.
 * To learn more click the highlighted Stop.
 *
 * The Route class contains the Stops class. It takes in multiple number of
 * stops to creates a route.The bus follow a route, which in turn follows stops.
 * To see all of its methods press the highlighted Route.
 *
 * The Bus class is the biggest of the classes and the most important because it
 * incorporates all of three other classes.
 * A bus has two routes(incoming and outgoing) and passengers.
 * I would highly recommend checking out the methods for bus as it will help
 * understand the bus simulator. click the highlighted Bus to check it out.
 *
 *
 */

#endif  // SRC_MAINPAGE_H_
