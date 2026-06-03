<?php
include("connect.php");
if(isset($_GET['distance']) && isset($_GET['status'])){
$Distance_detected=$_GET['Distance_detected'];
$Event_status=$_GET['Event_status'];
$conn->query("INSERT INTO intrusion_events(Distance_detected,Event_status)VALUES('$Distance_detected','$Event_status')");
 

}


?>