<?php 
	if(isset($_GET['pfile']))
		$pfile=$_GET['pfile'];
	else
		$pfile="";
	$prfile=urldecode($pfile);
?>

<html>
<body bgcolor="#808080">
<center>
<audio controls autoplay>
<source src="<?php echo '/music/'.$prfile;?>" type="audio/mpeg">
<embed height="10" width="20" src="<?php echo '/music/'.$prfile;?>">
</audio>
<br/><?php echo $prfile;?>
</center>
</body>
</html>