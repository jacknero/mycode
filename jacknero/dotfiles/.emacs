(add-to-list 'default-frame-alist '(foreground-color . "green"))
(add-to-list 'default-frame-alist '(background-color . "black"))
(add-to-list 'default-frame-alist '(cursor-color . "SlateBlue2"))
(add-to-list 'default-frame-alist '(mouse-color . "SlateBlue2"))
(set-face-foreground 'modeline "white")
(set-face-background 'modeline "MediumPurple2")
(set-face-background 'region "LightSteelBlue1")

(set-face-foreground 'mode-line-inactive "gray30")

(set-face-background 'mode-line-inactive "gray85")

(setq inhibit-splash-screen t)

(menu-bar-mode 0)

(tool-bar-mode 0)

(setq frame-title-format "%f")

(line-number-mode t)
(column-number-mode t)

;;(keyboard-translate ?\C-h ?\C-?)
;;(global-set-key "\C-h" nil)
;;(global-set-key "\C-h" 'delete-backward-char)
(define-key global-map "\C-h" 'delete-backward-char)

(set-language-environment "Japanese")
;(modify-coding-system-alias 'process "gosh" '(utf-8 . utf-8))
(setq scheme-program-name "gosh -i")
(autoload 'scheme-mode "cmuscheme" "Major mode for Scheme." t)
(autoload 'run-scheme " cmuscheme" "Run an inferior Scheme process." t)

(defun scheme-other-window  ()
  "Run scheme on other window"
  (interactive)
  (switche-to-buffer-other-window
    (get-buffer-create "*scheme*"))
  (run-scheme scheme-program-name))

(define-key global-map
            "\C-cs" 'scheme-other-window)


(setq load-path(cons "~/.emacs.d/elisp" load-path))

;; ~/elisp
(setq load-path
      (append
        (list
          (expand-file-name "~/elisp/")
          )
        load-path))


;; ruby-mode
(autoload 'ruby-mode "ruby-mode"
          "Mode for editing ruby source files" t)
(setq auto-mode-alist
      (append '(("\\.rb$" . ruby-mode)) auto-mode-alist))
(setq interpreter-mode-alist (append '(("ruby" . ruby-mode))
                                     interpreter-mode-alist))
(autoload 'run-ruby "inf-ruby"
          "Run an inferior Ruby process")
(autoload 'inf-ruby-keys "inf-ruby"
          "Set local key defs for inf-ruby in ruby-mode")
(add-hook 'ruby-mode-hook
          '(lambda () (inf-ruby-keys)))


;; ruby-electric
(require 'ruby-electric)
(add-hook 'ruby-mode-hook '(lambda () (ruby-electric-mode t)))

;; rubydb
(autoload 'rubydb "rubydb3x"
          "run rubydb on program file in buffer *gud-file*.
          the directory containing file becomes the initial working directory
          and source-file directory for your debugger." t)


;; rais
(setq load-path (cons (expand-file-name "~/elisp/emacs-rails/") load-path))
(defun try-complete-abbrev (old)
  (if (expand-abbrev) t nil))
(setq hippie-expand-try-functions-list
      '(try-complete-abbrev
         try-complete-file-name
         try-expand-dabbrev))
(setq rails-use-mongrel t)
(require 'cl)
(require 'rails)

;; ruby-block
(require 'ruby-block)
(ruby-block-mode t)
;; ミニバッファに表示し, かつ, オーバレイする.
(setq ruby-block-highlight-toggle 0 )

(define-key rails-minor-mode-map "\C-c\C-p" 'rails-lib:run-primary-switch)
(define-key rails-minor-mode-map "\C-c\C-n" 'rails-lib:run-secondary-switch)

;gosh
(modify-coding-system-alist 'process "gosh" '(utf-8 . utf-8))
(setq scheme-program-name "gosh -i")
(autoload 'scheme-mode "cmuscheme" "Major mode for Scheme." t)
(autoload 'run-scheme "cmuscheme" "Run an inteeerior Scheme profess." t)

(defun scheme-other-window ()
 "Run scheme on other window"
 (interactive)
 (switch-to-buffer-other-window
  (get-buffer-create "*scheme*"))
 (run-scheme scheme-program-name))

(define-key global-map
  "\C-cs" 'scheme-other-window)

;;文字化け防止
(set-clipboard-coding-system 'utf-8)
(setq x-select-enable-clipboard t)

;; flymake for ruby
(require 'flymake)
;; Invoke ruby with '-c' to get syntax checking
(defun flymake-ruby-init ()
  (let* ((temp-file   (flymake-init-create-temp-buffer-copy
                       'flymake-create-temp-inplace))
         (local-file  (file-relative-name
                       temp-file
                       (file-name-directory buffer-file-name))))
    (list "ruby" (list "-c" local-file))))
(push '(".+¥¥.rb$" flymake-ruby-init) flymake-allowed-file-name-masks)
(push '("Rakefile$" flymake-ruby-init) flymake-allowed-file-name-masks)
(push '("^¥¥(.*¥¥):¥¥([0-9]+¥¥): ¥¥(.*¥¥)$" 1 2 nil 3) flymake-err-line-patterns)
(add-hook
 'ruby-mode-hook
 '(lambda ()
    ;; Don't want flymake mode for ruby regions in rhtml files
    (if (not (null buffer-file-name)) (flymake-mode))
    ;; エラー行で C-c d するとエラーの内容をミニバッファで表示する
    (define-key ruby-mode-map "¥C-cd" 'credmp/flymake-display-err-minibuf)))

(defun credmp/flymake-display-err-minibuf ()
  "Displays the error/warning for the current line in the minibuffer"
  (interactive)
  (let* ((line-no             (flymake-current-line-no))
         (line-err-info-list  (nth 0 (flymake-find-err-info flymake-err-info line-no)))
         (count               (length line-err-info-list))
         )
    (while (> count 0)
      (when line-err-info-list
        (let* ((file       (flymake-ler-file (nth (1- count) line-err-info-list)))
               (full-file  (flymake-ler-full-file (nth (1- count) line-err-info-list)))
               (text (flymake-ler-text (nth (1- count) line-err-info-list)))
               (line       (flymake-ler-line (nth (1- count) line-err-info-list))))
          (message "[%s] %s" line text)
          )
        )
      (setq count (1- count)))))



 (setq gdb-many-windows t)
  (setq gdb-use-separate-io-buffer t) ; "IO buffer" が必要ない場合は  nil で

(defun my-insert-printf-debug ()
  (interactive)
  (insert-string "printf(¥"%s %s:%d¥¥n¥", __func__, __FILE__, __LINE__);")
  (indent-according-to-mode)
)

(add-hook 'c++-mode-hook
  (function (lambda ()
              (define-key c++-mode-map (kbd "C-c d") 'my-insert-printf-debug)
)))

(defface my-face-elisp-macro
  '((t (:foreground "sea green"))) nil)
(defface my-face-elisp-subr
  '((t (:foreground "purple"))) nil)
(defface my-face-elisp-func
  '((t (:foreground "medium blue"))) nil)
(defun my-font-lock-elisp-macro (limit)
  (when (re-search-forward
         "['(]¥¥([^() ¥n]+¥¥)" limit t)
    (or (and (not (memq (get-text-property
                         0 'face (match-string 1))
                        '(font-lock-comment-face
                          font-lock-warning-face)))
             (condition-case nil
                 (symbol-function
                  (intern-soft
                   (match-string-no-properties 1)))
               (error nil)))
        (my-font-lock-elisp-macro limit))))
(defun my-font-lock-elisp-subr (limit)
  (when (re-search-forward
         "['(]¥¥([^() ¥n]+¥¥)" limit t)
    (or (and (not (memq (get-text-property
                         0 'face (match-string 1))
                        '(font-lock-comment-face
                          font-lock-warning-face)))
             (subrp
              (condition-case nil
                  (symbol-function
                   (intern-soft
                    (match-string-no-properties 1)))
                (error nil))))
        (my-font-lock-elisp-subr limit))))
(defun my-font-lock-elisp-func (limit)
  (when (re-search-forward
         "['(]¥¥([^() ¥n]+¥¥)" limit t)
    (or (and (not (memq
                   (get-text-property
                    0 'face (match-string 1))
                   '(font-lock-comment-face
                     font-lock-warning-face)))
             (byte-code-function-p
              (condition-case nil
                  (symbol-function
                   (intern-soft
                    (match-string-no-properties 1)))
                (error nil))))
        (my-font-lock-elisp-func limit))))
(font-lock-add-keywords
 'lisp-interaction-mode
 '((my-font-lock-elisp-macro 1 'my-face-elisp-macro t)) t)
(font-lock-add-keywords
 'lisp-interaction-mode
 '((my-font-lock-elisp-func 1 'my-face-elisp-func t)) t)
(font-lock-add-keywords
 'lisp-interaction-mode
 '((my-font-lock-elisp-subr 1 'my-face-elisp-subr t)) t)
(font-lock-add-keywords
 'emacs-lisp-mode
 '((my-font-lock-elisp-macro 1 'my-face-elisp-macro t)) t)
(font-lock-add-keywords
 'emacs-lisp-mode
 '((my-font-lock-elisp-func 1 'my-face-elisp-func t)) t)
(font-lock-add-keywords
 'emacs-lisp-mode
 '((my-font-lock-elisp-subr 1 'my-face-elisp-subr t)) t)



(require 'cpp-complt)
(add-hook
 'c-mode-hook
 '(lambda()
    ;; C/C++ でヘッダを補完入力.
    (define-key c-mode-map "#" 'cpp-complt-instruction-completing)
    (define-key c-mode-map "¥C-c#" 'cpp-complt-ifdef-region)))

(add-hook 'c-mode-common-hook
          (function (lambda ()
                      (require 'cpp-complt)
                      (define-key c-mode-map [mouse-2]
                        'cpp-complt-include-mouse-select)
                      (define-key c-mode-map "#"
                        'cpp-complt-instruction-completing)
                      (define-key c-mode-map "¥C-c#"
                        'cpp-complt-ifdef-region)
                      (cpp-complt-init))))
;; まず、install-elisp のコマンドを使える様にします。
(require 'install-elisp)
;; 次に、Elisp ファイルをインストールする場所を指定します。
(setq install-elisp-repository-directory "~/.emacs.d/elisp/")

(require 'auto-complete)
(global-auto-complete-mode t)

;; iswitch
(iswitchb-mode 1)

;; anythin-el
(require 'anything-config)




