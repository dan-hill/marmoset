Installation {#installation}
============

Download the newest version of Marmoset:
----------------------------------------
You can clone the repository from our Github repository straight from the command line by navigating to the directory
you want to install Marmoset to and entering the following command.

    git clone https://github.com/dan-hill/marmoset.git

You can also download the source from http://github.com/dan-hill/marmoset.

Build the example application:
------------------------------
Now you can build the example application that is included with Marmoset by going to the marmoset directory and
running `make`. Marmoset and the example application will be compiled and a binary executable generated at 
`marmoset/bin/app`.

Running the example application:
--------------------------------
Open a terminal and go to `marmoset/bin` and start the application:
    $ ./app

The server should now be running on the default port 5555. You can now open an internet browser and go to 
[http://127.0.0.1:5555](http://127.0.0.1:5555) and you should see the Marmoset example webpage.