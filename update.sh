#!/bin/bash

cd /var/mobile/AD/

git add .
git commit -m "update of from AD $(date +'%Y-%m-%d %H:%M')"
git push origin main
gh pr create