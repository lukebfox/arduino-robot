/* BackEnd
* Written by: Tsz Ching suen
* First written: 27th October, 2018
* Last updated: 27th October, 2018
*/


// import sys
// print(sys);
// // sys.path.insert(0, "/Users/user/Documents/Hackathon/robot.py")
// // from Hackathon import robot.py;


// import site
// from org.python.util import jython
// jar_location = jython().getClass().getProtectionDomain().getCodeSource().getLocation().getPath()

// import site
// import os.path
// site.addsitedir(os.path.join(Users/user/jython2.7.0/jython.jar, 'Lib/site-packages'));



import org.python.core.*;
import org.python.util.*;

import java.lang.Object;

import org.python.core.PyInstance;  
import org.python.util.PythonInterpreter; 

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;





public class BackEnd implements KeyListener{

	private Command command = Command.STOP;
    enum Command {STOP, FORWARD, BACKWARD, PRIGHT, PLEFT, FRIGHT, FLEFT, BRIGHT, BLEFT};  

 
    PythonInterpreter interpreter = null; 


    public BackEnd(){

    	// Properties props = new Properties();
    	// props.setProperty("/Users/user/jython2.7.0/jython.jar");
        PythonInterpreter.initialize(System.getProperties(),  
                                   System.getProperties(), new String[0]);  

        this.interpreter = new PythonInterpreter(); 
      //this.addKeyListener(this); 
    }


	void execfile(final String fileName){
      this.interpreter.execfile(fileName);  
    }  

    PyInstance createClass(final String className, final String opts){
      return (PyInstance) this.interpreter.eval(className + "(" + opts + ")");  
    }


   	public void keyReleased(KeyEvent e) {
		command = Command.STOP;
    }


	//ignore everything else
	public void keyTyped(KeyEvent e) {}	


		public void keyPressed(KeyEvent e) {	
		switch ( e.getKeyCode()) {
			case java.awt.event.KeyEvent.VK_UP:
				command = Command.FORWARD;
				break;
			case java.awt.event.KeyEvent.VK_DOWN:
				command = Command.BACKWARD;
				break;
			case java.awt.event.KeyEvent.VK_LEFT:
				command = Command.FLEFT;
				break;
			case java.awt.event.KeyEvent.VK_RIGHT:
				command = Command.FRIGHT;
				break;
			case java.awt.event.KeyEvent.VK_A:
				command = Command.PLEFT;
				break;
			case java.awt.event.KeyEvent.VK_D:  
				command = Command.PRIGHT;
				break;	
			case java.awt.event.KeyEvent.VK_Z:
				command = Command.BLEFT;
				break;
			case java.awt.event.KeyEvent.VK_C:  
				command = Command.BRIGHT;
				break;	
			default:
				command = Command.STOP;
				break;
		}
	}


    public static void main(String[] args){ 

    	System.out.println("Robot is starting...");

        BackEnd pythoninjava = new BackEnd();
        pythoninjava.execfile("robot.py");
        pythoninjava.execfile("arduino.py");


        PyInstance pythonClass = pythoninjava.createClass("Robot", "None");
        //PyInstance pythonClass = pythoninjava.createClass("Robot", "None");


        
        while (true) {
			switch (new BackEnd().command) {
				case STOP:
					pythonClass.invoke("Stop");

					break;					
				case FORWARD:
					pythonClass.invoke("Forward");

					break;					
				case BACKWARD:
					pythonClass.invoke("Backward");

					break;					
				case FLEFT:
					pythonClass.invoke("FLeft");

					break;
				case FRIGHT:
					pythonClass.invoke("FRight");

					break;
				case PLEFT:
					pythonClass.invoke("PivotLeft");

 					break;
 				case PRIGHT:
 				    pythonClass.invoke("PivotRight");

 				    break;
 				case BLEFT:
 				    pythonClass.invoke("BLeft");

 				    break;
 				case BRIGHT:
 				    pythonClass.invoke("BRight");

 				    break;
			}
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {};
		}	
	}
}

// export PYTHONPATH=$PYTHONPATH:/Users/user/jython2.7.0/Lib/site-packages

