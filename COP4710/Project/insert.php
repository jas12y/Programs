<?php
	session_start();
	if(!isset($_SESSION['username']))
	{
		session_destroy();
		header("location:login.php");
	}
	if(isset($_POST['menu']))
	{
		header("location:menu.php");
	}
	if(isset($_POST['all']))
	{
		if($_POST['all'] == "Select All")	
			$checked=true;
		else
			$checked=false;
	}
	else
		$checked=false;

	include 'database_connector.php';
	$mysqli = new mysqli("localhost", "root", "", "music");
	$options=array("","Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other","Pop","R&B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical","Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise","Alternative Rock","Bass","Soul","Punk","Space","Meditative", "Instrumental Pop","Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native US","Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock","Folk","Folk-Rock","National Folk","Swing","Fast Fusion","Bebob","Latin","Revival","Celtic","Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock","Symphnic Rock","Slow Rock","Big Band","Chorus","Easy Listening","Acoustic","Humour","Speech","Chanson","Opera","Chamber Music","Sonata","Symphony","Booty Bass","Primus","Porn Groove","Satire","Slow Jam","Club","Tango","Samba","Folklore","Ballad","Power Balladv","Rhytmic Soul","Freestyle","Duet","Punk Rock","Drum Solo","Acapella","Euro-House","Dance Hall","Goa","Drum & Bass","Club-House","Hardcore","Terror","Indie","BritPop","Negerpunk","Polsk Punk","Beat","Christian Gangsta","Heavy Metal","Black Metal","Crossover","Contemporary C","Christian Rock","Merengue","Salsa","Thrash Metal","Anime","JPop","SynthPop");

	$caller="insert.php";
	$color=0;
	$DirectoryToScan = 'S:/Music';
	$dir = opendir($DirectoryToScan);
	require_once('../testread3/getID3-1.9.7/getid3/getid3.php');
	$getID3 = new getID3;
	$new=0;
	$dircheck=true;
?>

<html>
<body bgcolor="#808080">
<center>
<form action="insert.php" method="post"><input type="submit" name="menu" value="Main Menu"></form>
<br/>
<form action="insert.php" method="post">
<?php
	if(isset($_POST['edit']))
	{
		include 'edit.php';
	}
	else
	{
		if($checked)
		{
?>

<input type="submit" name="all" value="Select None">

<?php
		}
		else
		{
?>

<input type="submit" name="all" value="Select All">

<?php
		}
?>

<input type="submit" name="add" value="Add">
<input type="submit" name="edit" value="Edit">

<?php
	
		if(isset($_POST['update']))
		{
			include 'update.php';
		}
		if(isset($_POST['add']))
		{
			include 'add.php';
		}
?>

<br/><br/>
<table cellpadding="3">
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td align="center">Title</td>
<td align="center">Artist</td>
<td align="center">Album</td>
<td align="center">Genre</td>
<td align="center">Playtime</td>
<td align="center">File Name</td>
</tr>
<form action="insert.php" method="post">
<?php
		if($dircheck)
		{
		while ($file = readdir($dir))
		{

			$FullFileName = realpath($DirectoryToScan.'/'.$file);
			if ((substr($FullFileName, 0, 1) != '.') && is_file($FullFileName))
			{
				$ThisFileInfo = $getID3->analyze($FullFileName);
				getid3_lib::CopyTagsToComments($ThisFileInfo);
				$title = htmlentities(!empty($ThisFileInfo['comments_html']['title'])  ? implode(' ', $ThisFileInfo['comments_html']['title']): chr(160));
				$artist = htmlentities(!empty($ThisFileInfo['comments_html']['artist'])  ? implode(' ', $ThisFileInfo['comments_html']['artist']): chr(160));
				$album = htmlentities(!empty($ThisFileInfo['comments_html']['album'])  ? implode(' ', $ThisFileInfo['comments_html']['album']): chr(160));
				$genre = htmlentities(!empty($ThisFileInfo['comments_html']['genre'])  ? implode(' ', $ThisFileInfo['comments_html']['genre']): chr(160));
				$track = htmlentities(!empty($ThisFileInfo['comments_html']['track'])  ? implode(' ', $ThisFileInfo['comments_html']['track']): chr(160));
				$playtime = htmlentities(!empty($ThisFileInfo['playtime_string']) ? $ThisFileInfo['playtime_string'] : chr(160));

				$rfile = $mysqli->real_escape_string($file);
				//$rfile = html_entity_decode($file);

				$rtitle = html_entity_decode($title);
				$rartist = html_entity_decode($artist);
				$ralbum = html_entity_decode($album);
				$rgenre = html_entity_decode($genre);

				$result=mysqli_query($con,"select *from song where filename='$rfile'");
				$count=mysqli_num_rows($result);

				if($count==0)
				{
?>

<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>
<td>
<a href="player.php?pfile=<?php echo $file;?>" target="player"><img src="button_play_green.png" alt="Play" width="24" height="24"></a>
</td>
<td><input type="checkbox" name="checkbox[]" id="checkbox[]" <?php if($checked) echo 'checked'; ?> value="<?php echo $file;?>"></td>
<td><?php echo $rtitle; ?></td>
<td><?php echo $rartist; ?></td>
<td><?php echo $ralbum; ?></td>
<td><?php echo $rgenre; ?></td>
<td><?php echo $playtime; ?></td>
<td><?php echo $file; ?></td>
</tr>

<?php
					$color=$color+1;
					$new=$new+1;
				}
			}	
	        }
		echo '<strong>'.$new.' songs found'.'</strong><br/>';
		}
	}
?>
</table>
</form>
</center>
</body>
</html>