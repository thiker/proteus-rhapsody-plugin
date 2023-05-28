/*********************************************************************
	Rhapsody	: 9.0
	Login		: TK
	Component	: DefaultComponent
	Configuration 	: DefaultConfig
	Model Element	: DefaultConfig
//!	Generated Date	: Sun, 28, May 2023 
	File Path	: DefaultComponent/DefaultConfig/MainDefaultComponent.java
*********************************************************************/


//## auto_generated
import com.ibm.rational.rhapsody.oxf.*;
//## auto_generated
import com.ibm.rational.rhapsody.animcom.*;

//----------------------------------------------------------------------------
// MainDefaultComponent.java                                                                  
//----------------------------------------------------------------------------


//## ignore 
public class MainDefaultComponent {
    
    //#[ ignore
    // link with events in order to register them in the animation browser
    static {
      // Setting Animation Default Port 
      AnimTcpIpConnection.setDefaultPort(6423);
      // Registering Events 
      try {
        
    
        // Registering Static Classes 
        
      }
      catch(Exception e) { 
         java.lang.System.err.println(e.toString());
         e.printStackTrace(java.lang.System.err);
      }
    }
    //#]
    
    
    //## configuration DefaultComponent::DefaultConfig 
    public static void main(String[] args) {
        RiJOXF.Init(null, 0, 0, true, args);
        MainDefaultComponent initializer_DefaultComponent = new MainDefaultComponent();
        //#[ configuration DefaultComponent::DefaultConfig 
        System.out.println("test");
        //#]
        RiJOXF.Start();
    }
    
}
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/MainDefaultComponent.java
*********************************************************************/

