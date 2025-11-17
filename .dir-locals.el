((nil . ((eval . (progn
                   (defun norm-check-current-file ()
                     "Run norminette on the current file in its directory."
                     (interactive)
                     (when (buffer-file-name)
                       (let ((filename (file-name-nondirectory (buffer-file-name))))
                         (compile (concat "norminette -R CheckForbiddenSourceHeader " filename)))))

                   (defun cc-compile-current-file ()
                     "Run norminette on the current file in its directory."
                     (interactive)
                     (when (buffer-file-name)
                       (let ((filename (file-name-nondirectory (buffer-file-name))))
                         (compile (concat "cc -Werror -Wall -Wextra -I. *.c && ./a.out")))))

                   (defun norm-check-current-dir ()
                     "Run norminette on all files in the current project's root directory."
                     (interactive)
                     (let ((project-root (project-root (project-current))))
                       (if project-root
                           (let ((default-directory project-root))
                             (compile "norminette -R CheckForbiddenSourceHeader ."))
                         (message "Could not find project root."))))

                   (defun format-current-file ()
                     "Run c_formatter_42 on the current file and revert the buffer."
                     (interactive)
                     (when (buffer-file-name)
                       (let ((filename (file-name-nondirectory (buffer-file-name))))
                         (shell-command (concat "c_formatter_42 " filename))
                         (revert-buffer t t t)
                         (message "Formatted %s with c_formatter_42" filename))))))))

 (c-mode . ((indent-tabs-mode . t)
            (tab-width . 4)
            (c-basic-offset . 4)
            (eval . (local-set-key (kbd "C-c c c") 'norm-check-current-file))
            (eval . (local-set-key (kbd "C-c c r") 'cc-compile-current-file))
            (eval . (local-set-key (kbd "C-c c v") 'norm-check-current-dir))
            (eval . (local-set-key (kbd "C-c c f") 'format-current-file)))))
