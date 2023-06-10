<!DOCTYPE html>
<html>
<head>
  <title>간단한 텍스트 기반 게임</title>
</head>
<body>
  <h1>간단한 퀴즈 게임</h1>

  <?php
  $questions = array(
    "1. PHP는 어떤 용도로 사용되는가?",
    "2. PHP의 가장 최신 버전은 무엇인가?",
    "3. PHP에서 변수를 출력할 때 사용하는 함수는 무엇인가?"
  );

  $answers = array(
    "웹 개발",
    "PHP 8",
    "echo"
  );

  $totalQuestions = count($questions);
  $currentQuestion = isset($_GET['q']) ? $_GET['q'] : 1;

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $userAnswer = $_POST['answer'];

    if ($userAnswer == $answers[$currentQuestion - 1]) {
      echo "<p>정답입니다!</p>";
    } else {
      echo "<p>오답입니다. 정답은 '" . $answers[$currentQuestion - 1] . "'입니다.</p>";
    }

    $currentQuestion++;
  }

  if ($currentQuestion <= $totalQuestions) {
    echo "<p>" . $questions[$currentQuestion - 1] . "</p>";
    echo "<form method='post' action='?q=" . $currentQuestion . "'>";
    echo "<input type='text' name='answer' autofocus>";
    echo "<button type='submit'>다음</button>";
    echo "</form>";
  } else {
    echo "<p>게임이 종료되었습니다. 모든 질문에 대한 답변을 완료하였습니다.</p>";
  }
  ?>

</body>
</html>
