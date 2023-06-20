<?php
session_start();

if (isset($_POST['start'])) {
    $_SESSION['start_time'] = time();
}

if (isset($_POST['end'])) {
    if (isset($_SESSION['start_time'])) {
        $start_time = $_SESSION['start_time'];
        $end_time = time();
        $time_taken = $end_time - $start_time;
        unset($_SESSION['start_time']);
        echo $time_taken;
        exit;
    } else {
        echo "게임을 시작하세요.";
        exit;
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>공 움직이기 게임</title>
    <style>
        .container {
            position: relative;
            width: 400px;
            height: 400px;
            margin: 0 auto;
            border: 1px solid black;
        }
        #ball {
            position: absolute;
            width: 50px;
            height: 50px;
            background-color: red;
            border-radius: 50%;
        }
        #target {
            position: absolute;
            top: 150px;
            left: 300px;
            width: 50px;
            height: 50px;
            background-color: blue;
        }
    </style>
    <script>
        document.addEventListener("DOMContentLoaded", function() {
            var ball = document.getElementById("ball");
            var target = document.getElementById("target");
            var startTimeSet = false;

            ball.style.top = "0px";
            ball.style.left = "0px";

            document.addEventListener("keydown", function(event) {
                var ballTop = parseInt(ball.style.top);
                var ballLeft = parseInt(ball.style.left);

                switch (event.key) {
                    case "ArrowUp":
                        ball.style.top = (ballTop - 10) + "px";
                        break;
                    case "ArrowDown":
                        ball.style.top = (ballTop + 10) + "px";
                        break;
                    case "ArrowLeft":
                        ball.style.left = (ballLeft - 10) + "px";
                        break;
                    case "ArrowRight":
                        ball.style.left = (ballLeft + 10) + "px";
                        break;
                }

                if (!startTimeSet) {
                    startTimeSet = true;
                    startGame();
                }

                if (checkCollision(ball, target)) {
                    endGame();
                }
            });

            function checkCollision(ball, target) {
                var ballRect = ball.getBoundingClientRect();
                var targetRect = target.getBoundingClientRect();

                return !(ballRect.right < targetRect.left ||
                    ballRect.left > targetRect.right ||
                    ballRect.bottom < targetRect.top ||
                    ballRect.top > targetRect.bottom);
            }

            function startGame() {
                var xhr = new XMLHttpRequest();
                xhr.open("POST", "", true);
                xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                xhr.send("start=1");
            }

            function endGame() {
                var xhr = new XMLHttpRequest();
                xhr.open("POST", "", true);
                xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
                xhr.onreadystatechange = function() {
                    if (xhr.readyState === 4 && xhr.status === 200) {
                        alert("도달 시간: " + xhr.responseText + "초");
                    }
                };
                xhr.send("end=1");
            }
        });
    </script>
</head>
<body>
    <div class="container">
        <div id="ball"></div>
        <div id="target"></div>
    </div>
</body>
</html>
