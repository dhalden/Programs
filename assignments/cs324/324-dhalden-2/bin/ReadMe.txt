READCME File
============

The files in this collection include the three source files for the Skidmore MVC Library along with three demo files
that use the library to implement a simple GUI program.

The library files:
-----------------

SLView - this defines the GUI that programmers can configure to produce a graphical interface.
SLModel - a model contains the data that a program uses when interacting with the view.
SLController - this is the "middle man", an object that coordinates communications between view and model.

In most cases, SLView does not need to be edited or subclassed.  Use it as it is.
SLModel and SLController are abstract classes that must be subclassed.  See Controller and Model for examples
of subclasses.

Note that a "main" method is included in SLView - this is just for demo purposes.  You can run it to view the GUI
with all it's components displayed. It does not involve SLModel and SLController since these are abstract classes. 


Demo files:
----------

Any program using the MVC library should provide subclasses of SLModel and SLController in order to design a valid
Model-View-Controller pattern.  Study Main, the main class for the demo.  It constructs the three major components
(view, controller, and model) and links them together using using the register...() methods.  main() also defines
the view's components by excluding the pieces that are not to be displayed.  Also note that SLView has two constructors.
One includes the number of rows and columns for the grid of buttons as parameters; the other is used whenever the
button grid is not to be used.

Important note:

The register methods use SLController and SLModel.  In reality, the objects will be instantiated from subclasses.
Thus, for example, when model object accesses the controller, the following syntax must be used:

((Controller)controller).passStringToView(str);

(This assumes "Controller" is the user defined subclass of SLController.)

Similarly, type cast model (or whatever the user has named the reference) using "((Model)model".  This also assumes
"Model" is the name of the subclass of SLModel.


P. von Kaenel
January 2014