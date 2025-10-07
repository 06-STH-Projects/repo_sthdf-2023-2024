# save as scripts/verify_md_links.py  (spúšťaj z rootu repo)
import os, re, urllib.parse

ROOT = "docs"
LINK_RE = re.compile(r"\[[^\]]*\]\((?!https?://)(?!mailto:)([^)]+\.md)\)")

missing = []
for dirpath, _, files in os.walk(ROOT):
    for fn in files:
        if not fn.endswith(".md"):
            continue
        src = os.path.join(dirpath, fn)
        with open(src, "r", encoding="utf-8", errors="ignore") as f:
            text = f.read()
        for m in LINK_RE.finditer(text):
            href = m.group(1).strip()
            # strip anchors "file.md#anchor"
            href_no_anchor = href.split("#", 1)[0]
            # URL-decode (%20, %3A...)
            href_dec = urllib.parse.unquote(href_no_anchor)
            # resolve relative to source file dir
            target = os.path.normpath(os.path.join(os.path.dirname(src), href_dec))
            if not os.path.isfile(target):
                missing.append((src, href, target))

if not missing:
    print("✅ All markdown links resolve.")
else:
    print("❌ Broken links:")
    for src, href, target in missing:
        print(f"- in: {src}\n  link: {href}\n  → missing file: {target}\n")