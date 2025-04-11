<?php
$correct_username = 'admin';
$password = '1234';
$owner_phone = '9876543210';
$api_key = 'OF7XERC4PA3z9BTkYnQy2qV0raWvSpL56eMcswGgHljxohZuUIfb5ZI7Pgw2JYr8AE691nNjmxHhuiOv';

$username = $_POST['username'];
if ($username === $correct_username) {
  $msg = urlencode("Your password is $password. A forgot password request was triggered.");
  file_get_contents("https://www.fast2sms.com/dev/bulkV2?authorization=$api_key&sender_id=FSTSMS&message=$msg&language=english&route=v3&numbers=$owner_phone");
  echo "<script>alert('Password sent to your phone.'); window.location='index.html';</script>";
} else {
  echo "<script>alert('Username not recognized.'); window.location='index.html';</script>";
}
?>