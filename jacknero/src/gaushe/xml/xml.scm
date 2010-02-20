(use sxml.ssax)
  (use sxml.sxpath)
  
  (define xml
      "<blog>
        <title>ブログ</title>
            <author>誰か</author>
                <author><ghost>もう一人</ghost></author>
                  </blog>")
  
  (define (test sxml path)
        (format #t "~s => ~s\n" path ((sxpath path) sxml)))
  
  (let1 sxml (call-with-input-string xml 
                                                    (lambda (in) (ssax:xml->sxml in '())))
            (test sxml '(blog title))
                (test sxml '(blog author))
                    (test sxml '(blog author ghost))
                        (test sxml '(blog date)))
