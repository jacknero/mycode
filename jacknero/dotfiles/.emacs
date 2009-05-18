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