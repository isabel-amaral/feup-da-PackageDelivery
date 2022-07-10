## DA_T12_G37 - Package Delivery

> **2021/2022** - 2nd Year, 2nd Semester
> 
> **Course** - DA (Desenho de Algoritmos)
> 
> **Project developed by**
> - Guilherme Moreira (up202007036)
> - Isabel Amaral (up202006677)
> - Milena Gouveia (up202008862)

### Project Description

A package delivery company receives every day many packages with different sizes and weights and must deliver as many of these as possible using a set of available couriers each using a van with a certain capacity (total size and total weight). There are two different types of deliveries: normal and express, which need to be delivered in the same day they're placed. 

The purpose of this project was to implement a series of algorithms to optmize different given scenarios in order to help the company manage all the deliveries. 

### Implemented Scenarios

The three different optimization scenarios were described in the project's description (pt) - [here](./docs/project-description.pdf):

- **Minimize used couriers** - given a set of normal delivery packages with different sizes and weights and a set of available couriers, the goal was to maximize the number of those packages delivered in a day (preferably all packages) while trying to minimize the number of couriers used.
- **Maximize the company's profit** - given a set of normal delivery packages with different sizes, weights and cost (value paid by the customer to the company) and a set of available couriers, also with different costs (value paid by the company to the courier in exchange for performing the delivery), the goal was to maximize the company's profit (total delivered packages cost - total used couriers cost).
- **Maximize the number of express deliveries** - given a set of express delivery packages, each with an estimated delivery time, and knowing express deliveries must be done one at a time using a special van (no couriers involved), the goal was to select a set of packages to deliver in order to maximize the number of packages delivered in a day.

Other implemented features:

- **Non-Delivered Packages** (extra) - In all of the scenarios, if it's not possible to deliver all the packages, there's the possibility of transfering all those deliveries to the next day assigning them a higher priority for each day that passes without it being possible to make the delivery. Every day, first we try to deliver all packages with higher priority, only then, if there's space/time left, we try to deliver some other packages with lower priority.
- **Interactive Menu** - In order to test and demonstrate the different scenarios, we created a simple menu.
- **Code documentation** - All the implemented classes were documented using doxygen. The complete generated documentation can be checked in the [docs directory](./docs/output/html/). Alternatively just open the [index.html](./docs/output/html/index.html) in your browser.

### Program Development State

Overall all the scenarios implemented seemed to be working properly. We learned in which contexts it makes sense to use some commonly used algorithm design techniques, such as greedy algorithms, backtracking and dynamic programming.

For a more detailed project report (pt), check out ppt presentation [here](./docs/presentation.pdf).
