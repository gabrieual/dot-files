return {
  {
    "ellisonleao/gruvbox.nvim",
    priority = 1000,
    config = function()
      require("gruvbox").setup({
        contrast = "hard",
        italic = { strings = false, comments = true, folds = true },
      })
      vim.cmd("colorscheme gruvbox")
    end,
  },
}
