<?php
include("connect.php");
$id=$_GET['Id'];
$conn->query("DELETE FROM Intrusion_events WHERE Id='$id'");
header("location:index.php");
exit();
?>