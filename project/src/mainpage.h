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
 *
 * \subsection Decorator_pattern Decorator Pattern
 * For the third iteration we were tasked to implment a decorator pattern.
 * The pattern is going to aid in changing bus colors depending on their routes
 * and also their color intensity depending on the number of passengers they had
 * on. A decorator pattern allows adding new behaviors to objects dynamically
 * by placing them inside special wrapper objects. Lets say you have created a
 * pizza class with the only method in it is getcost(). Now we want to add
 * toppings to the pizza. This is where the decorator pattern plays a role.
 * We can create different objects for each of the toppings and wrap the Pizza
 * object with the topping object. So we can make a pepperoni object and wrap it
 * with your pizza object and now you have made a pepperoni pizza object. Next
 * we will take a look at two ways of implementing the decorator pattern for our
 * bus.
 *
 * \subsection first_implementation Version 1 (I would have implemented this)
 * You can think of verison 1 as a concerete implementation. We first start off
 * with a interface class for bus, which has all the mthods for bus and
 * decorator. Next we have the bus class inherit from this interface class. We
 * also make a second class called BusDecorator, which implements the color
 * change and intensity of the busses. With this now any time we wanted to
 * create a colored bus we would call the BusDecorator class.
 *
 * Pros: for this is that it requires less code to set up. We only had to create
 * two additonal classes to make it work. Another thing is that this way goes
 * with interface segregation.
 *
 * Cons: This way is not open to extension and closed to modification. This also
 * is not a single responsibilty.
 * ![version1pattern](@ref Version_1_DP.png)
 *
 * \subsection second_implementation Version 2
 * The second way to implement this is by seperating the methods in BusDecorator
 * into individual classes. With the image below we can see that instead of
 * having BusIntensity and BusColor inside BusDecorator we seperate it out and
 * create their own classes.
 *
 * Pros: This is a better way to implement the decorator pattern if we were
 * going to add additonal decorator elements. This way is also open for
 * extension and closed for modification, as we can just add another decorator
 * without altering anything.
 *
 * Cons: Requires more code upfront and in smaller application like this we
 * don't really need to care about more decorator specifications coming in.
 *
 * ![version2pattern](@ref Version_2_DP.png)
 *
 * \subsection Observer_Pattern Observer Pattern
 * For the second iteration we were tasked to
 * implement an observer pattern. A observer pattern
 * like the name suggests is a design to let
 * users track a object/item. This helps the
 * user keep track of any changes that happen
 * to the item being observed. In the case of the
 * bus sim we were tasked to create an observer pattern
 * for the bus class. We wanted to let the user
 * monitor a bus along it's route, while giving the
 * user current info about the bus capacity,
 * position, and number of passengers anytime it
 * moved.
 * ![Observerpattern](@ref observer_pattern.png)
 *
 * \subsection Implementation Observer Pattern Implementation
 * The way we implmnted an observer pattern for bus was
 * first by creating an abstract IObserver class. The only
 * method in the class was a notify method, which other
 * classes had to implment if they were inheriting.
 * This class acted as template for what info the users
 * wanted to see anytime a bus had moved.
 * Second we had to make an IObservable class. This
 * is where busses would be registered to be
 * observed or to be unobserved. This class
 * had three main methods. RegisterObserver,
 * ClearObservers, and NotifyObservers,
 * which the bus class inherits from. To
 * get better understanding of this idea, let us
 * go over how this works in the bus sim.
 * When the user clicks on a bus to observe, the RegisterObserver method
 * sends the BusData to be added to the
 * observer vector and at the
 * same time the ClearObservers clears the vector.
 * Now everytime the bus details are
 * updated, the NotifyObservers method is invoked
 * which calls the BusWebObserver class to
 * print the lastest bus info.
 * There are a few other classes that helped implementing
 * this observer pattern for bus, but I won't get
 * into it. I would recommend checking out the
 * UML provided below to better understand how everything is connected.
 *
 * ![Observer_Pattern](@ref Observer_UML.jpg)
 * ![Sequence diagram](@ref UML_sequence_diag.jpeg)
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
 *
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
