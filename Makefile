
MAKE = make --no-print-directory


all:
	@$(MAKE) -C ./libft -j$(nproc)
	@$(MAKE) -C ./libpf -j$(nproc)
	@$(MAKE) -C ./libtp -j$(nproc)
	@$(MAKE) -C ./liblg -j$(nproc)

clean:
	@$(MAKE) clean -C ./libft -j$(nproc)
	@$(MAKE) clean -C ./libpf -j$(nproc)
	@$(MAKE) clean -C ./libtp -j$(nproc)
	@$(MAKE) clean -C ./liblg -j$(nproc)

fclean:
	@$(MAKE) fclean -C ./libft -j$(nproc)
	@$(MAKE) fclean -C ./libpf -j$(nproc)
	@$(MAKE) fclean -C ./libtp -j$(nproc)
	@$(MAKE) fclean -C ./liblg -j$(nproc)

re: fclean all

.PHONY: clean, all, fclean, re
