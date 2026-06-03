<?php
include("connect.php");


?>



<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="refresh" content="3">
    <title>Document</title>
</head>
<body>
    <center>
        
        <h1>WELCOME TO DASHBOAD</h1>
        <h2>TABLE OF SECURITY EVENTS</h2>
        <table border=3px>
            <th>ID</th><th>DISTANCE_DETECTED</th><th>EVENTS_STATUS</th><th>TIMERECORDED</th><th>DELETE_DATA</th>
             <?php
             $result=$conn->query("SELECT * FROM Intrusion_events ORDER BY Id DESC");
             while($row=$result->fetch_assoc()){
                echo"
                <tr>
                <td>{$row['Id']}</td>
                <td>{$row['Distance_detected']}m</td>
                <td>{$row['Events_status']}</td>
                <td>{$row['timestamp']}</td>
                <td>
              <a href='delete.php?Id=".$row['Id']."'onclick=\"return confirm('delete this data?');\">delete</a>
              </td>

                </tr>
                
                
                ";
             }
             ?>
        </table>
        <a href="logout.php">LOGOUT</a>
    </center>
    
</body>
</html>