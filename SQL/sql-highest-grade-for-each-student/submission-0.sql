
SELECT student_id, exam_id, score
FROM exam_results e
WHERE exam_id = (
    SELECT MIN(exam_id)
    FROM exam_results
    WHERE student_id = e.student_id
      AND score = (
          SELECT MAX(score)
          FROM exam_results
          WHERE student_id = e.student_id
      )
)
ORDER BY student_id ASC;
