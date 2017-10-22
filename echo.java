/*TITLE : Implement a Multi-threading application for echo server using socket programming in JAVA.
ASSIGNMENT NO. : B9
BATCH NO. : T3
*/
/--------------------------------------server.java---------------------------------------

import java.io.*;
import java.net.*;
//import java.io.BufferedInputStream;
//import java.io.FileInputStream;
import java.io.IOException;
//import java.io.InputStream;

public class server
{
	public static void main(String args[])
	{
		int port = 6789;  //we can't choose a port less than 1024 if we are not privileged users (root)
		server s = new server( port );
		s.startServer();
    	}
    
    // declare a server socket and a client socket for the server
    
	ServerSocket echoServer = null;
	Socket client_socket = null;
    	int port;
    
    	public server( int port )
	{
		this.port = port;
   	}
    
	public void stopServer()
	{
		System.out.println( "Server is cleaned and exiting." );
		System.exit(0);
    	}
    
    	public void startServer()
	{
	        try
		{
			echoServer = new ServerSocket(port);
        	}
        	 catch (IOException e) 
		{
		    	System.out.println(e); // display whatever is read from the client
	        }   
	
		System.out.println( "Waiting for connections. Only one connection is allowed." );// it is displayed when client is not running
	
		while ( true )
		{
			try
			{
				client_socket = echoServer.accept();
				Server_Connection oneconnection = new Server_Connection(client_socket, this);
				oneconnection.run();
			}   
			catch (IOException e)
			{
				System.out.println(e);
		    	}
		}
	}    

}
class Server_Connection
{
	BufferedReader is;
	PrintStream os;
	Socket client_socket;
	server server;
    
	public Server_Connection(Socket client_socket, server server) 
	{
		this.client_socket = client_socket;
		this.server = server;
		System.out.println( "Connection established with : " + client_socket );
		try
	  	{
	    		is = new BufferedReader(new InputStreamReader(client_socket.getInputStream()));
		        os = new PrintStream(client_socket.getOutputStream());
	   	} catch (IOException e)
		{
	    		System.out.println(e);
		}
    	}
    
	public void run() 
	{
	        String line;
		try
		{
			boolean serverStop = false;
	                while (true) 
			{
				line = is.readLine(); // read line using the buffer reader meant for client socket
				System.out.println( "Received " + line );
		                int n = Integer.parseInt(line);
				if ( n == -1 ) // it indicates that client wants to stop.
				{
					serverStop = true;	
					break;
				}
				if ( n == 0 )
 				{
					System.out.println("want to start another client?  y/n");
					BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
					line=br.readLine();
					
					if(line=="n")
					 break;
					server.startServer();
					
				}
				else
				{	
		                	os.println("" + n*n ); 
				}

			}
	    		System.out.println( "Connection closed." );
		        is.close();
		        os.close(); // close the buffer readers
			client_socket.close();
	    		if ( serverStop ) 
				server.stopServer();
		} catch (IOException e)
		{
			System.out.println(e);
		}
    	}
}


//--------------------------------------client.java------------------------
import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
	
	String hostname = "localhost";
	int port = 6789;

	// declaration section:
		
        Socket clientSocket = null;     // clientSocket: our client socket
        DataOutputStream os = null;    // os: output stream
        BufferedReader is = null;     	// is: input stream
	
	// Initialization section:
	// Try to open a socket on the given port
	// Try to open input and output streams
	
        try {
            clientSocket = new Socket(hostname, port);
            os = new DataOutputStream(clientSocket.getOutputStream());
            is = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host: " + hostname);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to: " + hostname);
        }
	
	// If everything has been initialized then we want to write some data
	// to the socket we have opened a connection to on the given port
	
	if (clientSocket == null || os == null || is == null) {
	    System.err.println( "Something is wrong. One variable is null." );
	    return;
	}

	try {
	    while ( true ) {
		System.out.print( "Enter an integer (0 to stop connection, -1 to stop server): " );
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String keyboardInput = br.readLine();
		os.writeBytes( keyboardInput + "\n" );

		int n = Integer.parseInt( keyboardInput );
		if ( n == 0 || n == -1 ) {
		    break;
		}
		
		String responseLine = is.readLine();
		System.out.println("Server returns its square as: " + responseLine);
	    }
	    
	    // clean up:
	    // close the output stream
	    // close the input stream
	    // close the socket
	    
	    os.close();
	    is.close();
	    clientSocket.close();   
	} catch (UnknownHostException e) {
	    System.err.println("Trying to connect to unknown host: " + e);
	} catch (IOException e) {
	    System.err.println("IOException:  " + e);
	}
    }           
}


/*-----------------------------------------OUTPUT ON SERVER TERMINAL----------------
swl-04@Comp-SWL-04:~$ cd POOJ@P3
swl-04@Comp-SWL-04:~/POOJ@P3$ javac server.java
swl-04@Comp-SWL-04:~/POOJ@P3$ java server
Waiting for connections. Only one connection is allowed.
Connection established with : Socket[addr=/127.0.0.1,port=50002,localport=6789]
Received 2
Received 10
Received 0
want to start another client?  y/n
y
java.net.BindException: Address already in use
Waiting for connections. Only one connection is allowed.
Connection established with : Socket[addr=/127.0.0.1,port=50007,localport=6789]
Received 5
Received 100
Received -1
Connection closed.
Server is cleaned and exiting.
swl-04@Comp-SWL-04:~/POOJ@P3$ 

/*-----------------------------------------OUTPUT ON 1ST CLIENT'S TERMINAL----------------
swl-04@Comp-SWL-04:~$ cd POOJ@P3
swl-04@Comp-SWL-04:~/POOJ@P3$ javac client.java
swl-04@Comp-SWL-04:~/POOJ@P3$ java client
Enter an integer (0 to stop connection, -1 to stop server): 2
Server returns its square as: 4
Enter an integer (0 to stop connection, -1 to stop server): 10
Server returns its square as: 100
Enter an integer (0 to stop connection, -1 to stop server): 0
swl-04@Comp-SWL-04:~/POOJ@P3$ 

/*-----------------------------------------OUTPUT ON 2ND CLIENT'S TERMINAL----------------
swl-04@Comp-SWL-04:~$ javac client.java
javac: file not found: client.java
Usage: javac <options> <source files>
use -help for a list of possible options
swl-04@Comp-SWL-04:~$ cd POOJ@P3
swl-04@Comp-SWL-04:~/POOJ@P3$ javac client.java
swl-04@Comp-SWL-04:~/POOJ@P3$ java client
Enter an integer (0 to stop connection, -1 to stop server): 5
Server returns its square as: 25
Enter an integer (0 to stop connection, -1 to stop server): 100
Server returns its square as: 10000
Enter an integer (0 to stop connection, -1 to stop server): -1
swl-04@Comp-SWL-04:~/POOJ@P3$ */



