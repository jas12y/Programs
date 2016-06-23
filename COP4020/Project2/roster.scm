; John Stubbs
; FSU ID: jas12y

(define add-student
   (lambda (n lst)
     (cond ((= n 0) (begin
                      (display "\n\tStudent ID: ")
                      (add-student 1 (list (read-line)))
                     ))
           ((= n 1) (begin
                      (display "\n\tStudent name: ")
                      (add-student 2 (cons (car lst) (list (read-line))))
                     ))
           ((= n 2) (begin
                      (display "\n\tGrade: ")
                      (cons (car lst) (list (car (cdr lst)) (read-line)))
                     ))
      )
   )
)
(define display-list
   (lambda (lst count)
      (cond ((null? lst) #f)
            (else (begin
                    (display "\n\tNo.")
                    (display count)
                    (display ": ")
                    (display-item 0 (car lst))
                    (display-list (cdr lst) (+ count 1))
                  )
            )
      )
   )
)
(define display-item
   (lambda (n lst)
      (cond ((= n 0) (begin
                       (display "ID=")
                       (display (car lst))
                       (display-item 1 (cdr lst))
                      ))
            ((= n 1) (begin
                       (display ", Name=")
                       (display (car lst))
                       (display-item 2 (cdr lst))
                      ))
            ((= n 2) (begin
                       (display ", Grade=")
                       (display (car lst))
                      ))
      )
   )
)
(define sort-id
   (lambda (lst)
      (cond ((null? lst) '() )
            (else (cons (smallest-id lst (car lst)) (sort-id (remove lst (smallest-id lst (car lst))))
            ))
      )
   )
)
(define smallest-id
   (lambda (lst min)
      (cond ((null? lst) min)
            ((string<? (car (car lst)) (car min)) (smallest-id (cdr lst) (car lst)))
            (else (smallest-id (cdr lst) min))
      )
   )
)
(define sort-name
   (lambda (lst)
      (cond ((null? lst) '() )
            (else (cons (smallest-name lst (car lst)) (sort-name (remove lst (smallest-name lst (car lst))))
            ))
      )
   )
)
(define smallest-name
   (lambda (lst min)
      (cond ((null? lst) min)
            ((string<? (car (cdr (car lst))) (car (cdr min))) (smallest-name (cdr lst) (car lst)))
            (else (smallest-name (cdr lst) min))
      )
   )
)
(define sort-grade
   (lambda (lst)
      (cond ((null? lst) '() )
            (else (cons (smallest-grade lst (car lst)) (sort-grade (remove lst (smallest-grade lst (car lst))))
            ))
      )
   )
)
(define smallest-grade
   (lambda (lst min)
      (cond ((null? lst) min)
            ((string<? (car (cdr (cdr (car lst)))) (car (cdr (cdr min)))) (smallest-grade (cdr lst) (car lst)))
            (else (smallest-grade (cdr lst) min))
      )
   )
)
(define find-item
   (lambda (lst item)
      (cond ((equal? (car (car lst)) item) (begin
                                              (display "\n\t")
                                              (car lst)
                                           ))
            ((equal? (car (cdr (car lst))) item) (begin
                                                    (display "\n\t")
                                                    (car lst)
                                                 ))
            (else (find-item (cdr lst) item))
      )
   )
)
(define remove
   (lambda (lst item)
      (cond ((null? lst) '() )
            ((equal? (car lst) item) (cdr lst))
            (else (cons (car lst) (remove (cdr lst) item)))
      )
   )
)
(define performtask
  (lambda (n roster) 
    (cond ((= n 0) (begin
                    (display "\n\tRoster reset (now empty).\n")
                    (menu '())
                    ))
          ((= n 1) (begin
                    (display "\n\tLoad roster from file: ")
                    (menu (call-with-input-file (read-line) read))
                    ))
          ((= n 2) (begin
                    (display "\n\tStore roster to file: ")
                    (call-with-output-file (read-line)
                       (lambda (p)
                          (write roster p)
                       ))
                    (menu roster)
                    ))
          ((= n 3) (begin
                    (display "\n\tDisplaying roster, sorted by ID:\n")
                    (display-list (sort-id roster) 1)
                    (newline)
                    (menu roster)
                    ))
          ((= n 4) (begin
                    (display "\n\tDisplaying roster, sorted by name:\n")
                    (display-list (sort-name roster) 1)
                    (newline)
                    (menu roster)
                    ))
          ((= n 5) (begin
                    (display "\n\tDisplaying roster, sorted by grade:\n")
                    (display-list (sort-grade roster) 1)
                    (newline)
                    (menu roster)
                    ))
          ((= n 6) (begin
                    (display "\n\tEnter student name or ID: ")
                    (display-item 0 (find-item roster (read-line)))
                    (newline)
                    (menu roster)
                    ))
          ((= n 7) (begin
                    (display "\n\tAdd a student to the class roster:\n")
                    (menu (cons (add-student 0 '()) roster))
                    ))
          ((= n 8) (begin
                    (display "\n\tEnter student name or ID: ")
                    (menu (remove roster (find-item roster (read-line))))
                    ))
          ((= n 9) (begin
                    (display "\n\tGoodbye!\n")
                    #t
                    ))
           (else (begin
                    (display "\n\ttask no. ")
                    (display n)
                    (display " does not exist.\n\n")
                    (menu roster)
                 )
           )
    )
  )
)

(define menu
  (lambda (roster)
     (begin
        (display "\n\tClass roster management system\n")
        (display "\t============================\n")
        (display "\t   MENU\n")
        (display "\t============================\n")
        (display "\t0. Reset roster\n")
        (display "\t1. Load roster from file\n")
        (display "\t2. Store roster to file\n")
        (display "\t3. Display roster sorted by ID\n")
        (display "\t4. Display roster sorted by name\n")
        (display "\t5. Display roster sorted by grade\n")
        (display "\t6. Display student info\n")
        (display "\t7. Add student to roster\n")
        (display "\t8. Remove student from roster\n")
        (display "\t9. Exit\n\n")
        (display "\tEnter your choice: ")
        (performtask (read) roster)
      )
   )
)