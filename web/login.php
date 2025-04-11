<?php
$correct_username = 'veena';
$correct_password = 'veena123';
$owner_phone = '7729948081';
$api_key = 'OF7XERC4PA3z9BTkYnQy2qV0raWvSpL56eMcswGgHljxohZuUIfb5ZI7Pgw2JYr8AE691nNjmxHhuiOv';

session_start();
if (!isset($_SESSION['attempts'])) {
  $_SESSION['attempts'] = 0;
}

$username = $_POST['username'];
$password = $_POST['password'];

if ($username === $correct_username && $password === $correct_password) {
  $_SESSION['attempts'] = 0;
  file_get_contents("http://192.168.1.50/unlock");
  echo "<script>alert('Door unlocked!'); window.location='index.html';</script>";
} else {
  $_SESSION['attempts']++;
  if ($_SESSION['attempts'] >= 3) {
    $msg = urlencode("3 failed login attempts detected on your Smart Door system.");
    file_get_contents("https://www.fast2sms.com/dev/bulkV2?authorization=$api_key&sender_id=FSTSMS&message=$msg&language=english&route=v3&numbers=$owner_phone");
  }
  echo "<script>alert('Invalid credentials.'); window.location='index.html';</script>";
}
?>
