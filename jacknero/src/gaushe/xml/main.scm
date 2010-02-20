(use rfc.http)
(use sxml.ssax)
(use sxml.sxpath)
(let-values (((status head body) (http-get "zip.ricollab.jp" "/5340026")))
              (let ((xml (call-with-input-string body (cut ssax:xml->sxml <> '((xhtml . "http://www.w3.org/1999/xhtml"))))))
                    ; //xhtml:dd[@class = 'address']
                         ((sxpath '(// (xhtml:dd (@ (equal? (class "address")))))) xml))
             (display body) )
