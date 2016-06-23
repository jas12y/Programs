<html>
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
	if(isset($_POST['dall']))
	{
		if($_POST['dall'] == "Select All")	
			$dchecked=true;
		else
			$dchecked=false;
		$_POST['delete']="Delete";
	}
	else
		$dchecked=true;
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
	$options=array("","NULL","Blues","Classic Rock","Country","Dance","Disco","Funk","Grunge","Hip-Hop","Jazz","Metal","New Age","Oldies","Other","Pop","R&B","Rap","Reggae","Rock","Techno","Industrial","Alternative","Ska","Death Metal","Pranks","Soundtrack","Euro-Techno","Ambient","Trip-Hop","Vocal","Jazz+Funk","Fusion","Trance","Classical","Instrumental","Acid","House","Game","Sound Clip","Gospel","Noise","Alternative Rock","Bass","Soul","Punk","Space","Meditative", "Instrumental Pop","Instrumental Rock","Ethnic","Gothic","Darkwave","Techno-Industrial","Electronic","Pop-Folk","Eurodance","Dream","Southern Rock","Comedy","Cult","Gangsta","Top 40","Christian Rap","Pop/Funk","Jungle","Native US","Cabaret","New Wave","Psychadelic","Rave","Showtunes","Trailer","Lo-Fi","Tribal","Acid Punk","Acid Jazz","Polka","Retro","Musical","Rock & Roll","Hard Rock","Folk","Folk-Rock","National Folk","Swing","Fast Fusion","Bebob","Latin","Revival","Celtic","Bluegrass","Avantgarde","Gothic Rock","Progressive Rock","Psychedelic Rock","Symphnic Rock","Slow Rock","Big Band","Chorus","Easy Listening","Acoustic","Humour","Speech","Chanson","Opera","Chamber Music","Sonata","Symphony","Booty Bass","Primus","Porn Groove","Satire","Slow Jam","Club","Tango","Samba","Folklore","Ballad","Power Balladv","Rhytmic Soul","Freestyle","Duet","Punk Rock","Drum Solo","Acapella","Euro-House","Dance Hall","Goa","Drum & Bass","Club-House","Hardcore","Terror","Indie","BritPop","Negerpunk","Polsk Punk","Beat","Christian Gangsta","Heavy Metal","Black Metal","Crossover","Contemporary C","Christian Rock","Merengue","Salsa","Thrash Metal","Anime","JPop","SynthPop");
	$caller='search.php';
	$color=0;
	$DirectoryToScan = 'S:/Music';
	$dir = opendir($DirectoryToScan);
	require_once('../testread3/getID3-1.9.7/getid3/getid3.php');
	$getID3 = new getID3;
	if(!empty($_POST['favorite']))
	{
		foreach($_POST['favorite'] as $fav)
		{
			$user = $_SESSION['username'];
			$addFav=mysqli_query($con,"INSERT INTO favs (songid,userid)
									SELECT s.songid, u.userid
									FROM song s,users u
									WHERE s.title='$fav' AND u.userid='$user'");
			if($addFav)
				echo '<center>'.$fav.' added to favorites'.'</center><br/>';
		}
	}

	if(isset($_POST['title']))
	{
		$rtitle=$_POST['title'];
		$rartist=$_POST['artist'];
		$ralbum=$_POST['album'];
		$rgenre=$_POST['genre'];
		$group=$_POST['group'];

		$title = htmlentities($rtitle);
		$artist = htmlentities($rartist);
		$album = htmlentities($ralbum);
		$genre = htmlentities($rgenre);

		$_POST['submit']="Search";
	}
	else
	{
		$title="";
		$artist="";
		$album="";
		$genre="";
		$group="";
	}
?>


<body bgcolor="#808080">
<center>
<br/>
<form action="search.php" method="post"><input type="submit" name="menu" value="Main Menu"></form>
<br/>
<form action="search.php" method="post">
<table width="200" border="0">
<tr>
<td>Title</td>
<td>&nbsp;</td>
<td>
<input name="title" type="text" id="title" value="<?php echo $title;?>">
</td>
</tr>
<tr>
<td>Artist</td>
<td>&nbsp;</td>
<td>
<input name="artist" type="text" id="artist" value="<?php echo $artist;?>">
</td>
</tr>
<tr>
<td>Album</td>
<td>&nbsp;</td>
<td>
<input name="album" type="text" id="artist" value="<?php echo $album;?>">
</td>
</tr>
<tr>
<td>Genre</td>
<td>&nbsp;</td>
<td>
<select name="genre" value="<?php echo $genre;?>">

<?php
	foreach($options as $id)
	{
?>

<option value="<?php echo $id;?>" <?php if($genre == $id) echo "SELECTED"; ?> ><?php echo $id;?></option>

<?php
	}
?>

</select>
</td>
</tr>
<tr>
<td>Sort by</td>
<td>&nbsp;</td>
<td>
<select name="group">
<option value="s.title" <?php if($group=="s.title") echo "SELECTED"; ?> >Title</option>
<option value="s.artist" <?php if($group=="s.artist") echo "SELECTED"; ?> >Artist</option>
<option value="a.title" <?php if($group=="a.title") echo "SELECTED"; ?> >Album</option>
<option value="s.genre" <?php if($group=="s.genre") echo "SELECTED"; ?> >Genre</option>
</select>
</td>
</tr>
</table>
<input type="submit" name="submit" value="Search">

<?php
	if(isset($_POST['delete']))
	{
		include 'delete.php';
	}
	else
	{
		if(isset($_POST['edit']))
		{
			include 'edit.php';
		}
		else
		{
?>
<input type="submit" name="favs" value="Favorites">
<input type="submit" name="edit" value="Edit">
<input type="submit" name="delete" value="Delete">

<?php
			if($checked)
			{
?>

<input type="submit" name="all" value="Select None">
<br/>

<?php
			}
			else
			{
?>


<input type="submit" name="all" value="Select All">
<br/>

<?php
			}
		}
	}
	if(isset($_POST['update']))
	{
		include 'update.php';
	}
	if(isset($_POST['dbdelete']))
	{
		include 'dbdelete.php';
	}
	if(isset($_POST['submit']) && !isset($_POST['edit']))
	{
		if($album=="")
		{
			if($genre=="NULL" && strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist='' AND genre='') s 
								LEFT JOIN (SELECT *
										FROM album
										WHERE genre='') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			elseif($genre=="NULL")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist LIKE '%$artist%' AND genre='') s 
								LEFT JOIN (SELECT *
										FROM album
										WHERE genre='') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			elseif(strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist='' AND genre LIKE '%$genre%') s 
								LEFT JOIN (SELECT *
										FROM album
										WHERE genre LIKE '%$genre%') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			else
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist LIKE '%$artist%' AND genre LIKE '%$genre%') s 
								LEFT JOIN (SELECT *
										FROM album
										WHERE genre LIKE '%$genre%') a
								ON (SELECT DISTINCT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
		}
		elseif(strtolower($album)=="null")
		{
			if($genre=="NULL" && strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, s.genre, s.playtime, s.filename  
								FROM (SELECT *
									FROM song
									WHERE songid NOT IN (SELECT songid FROM ison)) s
								WHERE s.title LIKE '%$title%' AND s.artist='' AND s.genre=''
								ORDER BY $group
								");
			}
			elseif($genre=="NULL")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, s.genre, s.playtime, s.filename  
								FROM (SELECT *
									FROM song
									WHERE songid NOT IN (SELECT songid FROM ison)) s
								WHERE s.title LIKE '%$title%' AND s.artist LIKE '%$artist%' AND s.genre=''
								ORDER BY $group
								");
			}
			elseif(strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, s.genre, s.playtime, s.filename  
								FROM (SELECT *
									FROM song
									WHERE songid NOT IN (SELECT songid FROM ison)) s
								WHERE s.title LIKE '%$title%' AND s.artist='' AND s.genre LIKE '%$genre%'
								ORDER BY $group
								");
			}
			else
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, s.genre, s.playtime, s.filename  
								FROM (SELECT *
									FROM song
									WHERE songid NOT IN (SELECT songid FROM ison)) s
								WHERE s.title LIKE '%$title%' AND s.artist LIKE '%$artist%' AND s.genre LIKE '%$genre%'
								ORDER BY $group
								");
			}
		}
		else
		{
			if($genre=="NULL" && strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist='' AND genre='') s 
								RIGHT JOIN (SELECT *
										FROM album
										WHERE title LIKE '%$album%' AND genre='') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			elseif($genre=="NULL")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist LIKE '%$artist%' AND genre='') s 
								RIGHT JOIN (SELECT *
										FROM album
										WHERE title LIKE '%$album%' AND genre LIKE '%$genre%') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			elseif(strtolower($artist)=="null")
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist='' AND genre LIKE '%$genre%') s 
								RIGHT JOIN (SELECT *
										FROM album
										WHERE title LIKE '%$album%' AND genre LIKE '%$genre%') a
								ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
			else
			{
				$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (SELECT * 
									FROM song 
									WHERE title LIKE '%$title%' AND artist LIKE '%$artist%' AND genre LIKE '%$genre%') s 
								RIGHT JOIN (SELECT *
										FROM album
										WHERE title LIKE '%$album%' AND genre LIKE '%$genre%') a
								ON (SELECT DISTINCT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid)
								ORDER BY $group
								");
			}
		}
		if(isset($_POST['favs']))
		{
			$user = $_SESSION['username'];
			$result=mysqli_query($con,"SELECT s.title, s.artist, a.title album, s.genre, s.playtime, s.filename  
								FROM (song s LEFT JOIN album a
									ON (SELECT songid
									FROM ison
									WHERE s.songid=songid AND a.albumid=albumid))
								WHERE (SELECT f.songid
									FROM favs f
									WHERE s.songid=f.songid AND f.userid='$user')
								ORDER BY $group
								");
		}

		if($result)
		{
			$count=mysqli_num_rows($result);
			echo '<strong>'.$count.' songs found'.'</strong><br/>';
			
?>
<br/><br/>
<table cellpadding="3">
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td align="center">Title</td>
<td align="center">Fav.</td>
<td align="center">Artist</td>
<td align="center">Album</td>
<td align="center">Genre</td>
<td align="center">Playtime</td>
<td align="center">File Name</td>
</tr>

<?php
			while($row=mysqli_fetch_array($result))
        		{
			

				$rtitle = $row['title'];
				$rartist = $row['artist'];
				$rgenre = $row['genre'];
				$file = $row['filename'];
				$rfile = $mysqli->real_escape_string($file);

			//echo $rtitle.' '.$file.' ';
				if(strtolower($album)=="null")
					$row['album']="";
				if(strtolower($artist)=="null")
					$row['artist']="";

?>

<tr bgcolor='<?php if(($color%2)==0) echo "#688e23"; else echo "#d3d3d3"; ?>'>
<td>
<a href="player.php?pfile=<?php echo urlencode($file);?>" target="player"><img src="button_play_green.png" alt="Play" width="24" height="24"></a>
</td>
<td><input type="checkbox" name="checkbox[]" id="checkbox[]" <?php if($checked) echo 'checked'; ?> value="<?php echo $row['filename']; ?>"></form></td>
<td><?php echo $row['title']; ?></td>
<td><input type="checkbox" name="favorite[]" id="favorite[]" value="<?php echo $row['title']; ?>"></form></td>
<td><?php echo $row['artist']; ?></td>
<td><?php echo $row['album']; ?></td>
<td><?php echo $row['genre']; ?></td>
<td><?php echo $row['playtime']; ?></td>
<td><?php echo $row['filename']; ?></td>
</tr>

<?php 
				$color=$color+1;
        		}
		}
	}
?>

</table>
</form>
</center>
</body>	
</html>



<!--****************************************************************************************************************************************************************
SELECT s.title, s.artist, a.title, s.genre, s.playtime, s.filename  
FROM song s
LEFT JOIN ison i
ON s.songid = i.songid
LEFT JOIN album a 
ON s.title LIKE '%' AND s.artist LIKE '%' AND a.title LIKE '%' AND s.genre=a.genre
GROUP BY s.title;

SELECT s.title, s.artist, s.genre, s.playtime, s.filename
FROM song s
WHERE s.title LIKE '%' AND s.artist LIKE '%' AND s.genre LIKE '%'
SELECT a.title
FROM album a
WHERE a.title LIKE '%$album%'

SELECT *
FROM song s
WHERE s.songid NOT IN (SELECT songid FROM ison);

SELECT s.title, a.title, s.playtime
FROM (SELECT *FROM song WHERE title LIKE '%vs%' AND artist LIKE '%' AND genre LIKE '%') s
LEFT JOIN (SELECT title FROM album WHERE title=null ) a
ON s.songid NOT IN (SELECT songid FROM ison)
ORDER BY $group

SELECT s.title, s.playtime
FROM (SELECT *FROM song WHERE songid NOT IN (SELECT songid FROM ison)) s
WHERE s.title LIKE '%' AND s.artist LIKE '%' AND s.genre LIKE '%'

SELECT *
FROM song s
WHERE s.genre = "";

SELECT s.songid, a.albumid
FROM (SELECT *FROM song WHERE title LIKE '%' AND artist LIKE '%' AND genre LIKE '%') s
LEFT JOIN (SELECT *FROM album WHERE title LIKE '%' AND genre LIKE '%') a
ON (SELECT songid FROM ison WHERE s.songid=songid AND a.albumid=albumid);

SELECT s.title, a.title album, s.genre, s.playtime
FROM (song s LEFT JOIN album a
ON (SELECT songid
FROM ison
WHERE s.songid=songid AND a.albumid=albumid))
WHERE (SELECT f.songid
FROM favs f
WHERE s.songid=f.songid AND f.userid='test')
******************************************************************************************************************************************************************-->