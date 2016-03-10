<?php
$data =$_POST['df1']."".$_POST['df2']."".$_POST['df3']."".$_POST['df4']."".$_POST['df5']."".$_POST['df6']."".$_POST['df7']."".$_POST['df8'];	//data is 8 values
$filename = "dblist.txt";

$myfile = fopen($filename, "w") or die("Unable to open file!");		//open dblist.txt
fwrite($myfile,  $data );	//write data to dblist.txt
if(file_exists($filename)){		//test if file exist or not
	echo file_get_contents($filename);	//read file content
}
fclose($myfile);	//close opening-handle 
?>