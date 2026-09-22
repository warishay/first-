#!/usr/bin/env bash
# ==============================================================================
# Daily Task Git Automation Script
# Usage:
#   ./daily_commit.sh "Day 01: Basics and Input/Output"
# ==============================================================================

set -e

MSG="$1"

if [ -z "$MSG" ]; then
  echo "❌ Error: Please provide a commit message."
  echo "Usage: ./daily_commit.sh \"Day XX: Your task description\""
  exit 1
fi

echo "🔍 1. Running compilation check..."
if command -v make >/dev/null 2>&1; then
  make clean >/dev/null 2>&1 || true
  make all
  echo "✅ Compilation check passed!"
else
  echo "⚠️ make not found, skipping compile check."
fi

echo "📦 2. Staging changed files..."
git add .

echo "📝 3. Committing: $MSG"
git commit -m "$MSG"

echo "🚀 4. Pushing to GitHub (origin main)..."
if git push origin main; then
  echo "🎉 Successfully submitted daily task to GitHub!"
else
  echo ""
  echo "⚠️ Push failed. Please check your GitHub write permissions for this repository."
  echo "Tip: Ensure you are logged into GitHub CLI (gh auth login) with write access, or set up an SSH key."
fi
