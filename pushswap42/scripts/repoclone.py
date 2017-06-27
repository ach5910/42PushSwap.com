from git import Repo
import sys

def clone_repo(url):
    print("\n\n" + str(url) + "\n\n")
    Repo.clone_from(url, "../repo/push_swap")
    