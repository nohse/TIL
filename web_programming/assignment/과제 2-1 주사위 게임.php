<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // 주사위 던지기
    $player1 = rand(1, 6);
    $player2 = rand(1, 6);

    // 결과 계산
    if ($player1 > $player2) {
        $result = "플레이어 1이 이겼습니다!";
    } elseif ($player1 < $player2) {
        $result = "플레이어 2가 이겼습니다!";
    } else {
        $result = "비겼습니다!";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>주사위 게임</title>
</head>
<body>
    <h1>주사위 게임</h1>
    <form method="POST" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
        <input type="submit" value="주사위 던지기">
    </form>

    <?php if ($_SERVER["REQUEST_METHOD"] == "POST"): ?>
        <h2>플레이어 1: <?php echo $player1; ?></h2>
        <h2>플레이어 2: <?php echo $player2; ?></h2>
        <h2>결과: <?php echo $result; ?></h2>
    <?php endif; ?>
</body>
</html>