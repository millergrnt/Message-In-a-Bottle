# Message-In-a-Bottle

Message in a Bottle is a C, command line based messaging system

<h5>Current State</h5>
Unthreaded and uses 1-1 messaging format where each message needs a reply before you can continue to message. This is simply for getting something working and then building upon it later.

<h2>Future wishes:</h2>

<ul>
    <li><del>Server: OpenSSL support for message security</del></li>
    <li>Client: OpenSSL support for message security</li>

  <li>A sending thread who will handle all of the user's input and send them so you can send multiple messages before getting replies</li>
  <li>A recieving thread who will handle all of the responses for the same goal</li>
  
  <li>Main server which will hold a database of all user's names and their DNS so you can chat with specific users</li>
  
  <li>Multiple messaging threads at once in different colors so you can differentiate the messages</li>
 </ul>
