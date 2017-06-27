from django.shortcuts import render, redirect
from django.contrib.auth import get_user_model
from django.db.models import Q
from django.views.generic import DetailView
from scripts.repoclone import clone_repo
from .models import Executable
from scripts.make_ps import make_ps
from scripts.repo_test import repo_test
import requests
import simplejson as json
from collections import defaultdict


CLIENT_ID = '90e918eda87296f5cf1368be3ee840b92a7ac4adad46385da51fcced164da76b'
CLIENT_SECRET = 'fd94fe3bcb22dbf507e14e5bac8edb273d6b70b512cf6f7323b951c3614f7447'
# def PushSwapHome(request):
#     return render(request, "pushswap42/detail.html'", {})
# class PushSwapHome(DetailView):
    


def get_return(request):
    model = Executable.objects.all()
    if (request.GET.get('code')):
        return render(request, "repo.html", {"object": model, "code":request.GET.get('code')})
    elif (request.GET.get('error')):
        print("elif")
        return render(request, "signin.html", {"object": model})
    else:
        return render(request, "signin.html", {"object": model})
# def success_login(request):
#     print('SUCCESS')
#     if(request.GET.get('code')):
#         print('SUCCESS')
        
# def error_login(request):
#     print('ERROR')
#     if(request.GET.get('error')):
#         print('ERROR')

def get_token(code):
    args = [
        'grant_type=authorization_code',
        'client_id=' + str(CLIENT_ID),
        'client_secret=' + str(CLIENT_SECRET),
        'code=' + str(code),
        'redirect_uri=http%3A%2F%2Flocalhost%3A8000%2F'
    ]
    client = requests.post("https://api.intra.42.fr/oauth/token?%s" % ("&".join(args)))
    token_json = client.json()
    print(json.dumps(token_json))
    return token_json['access_token']

def request_page(request):
    model = Executable.objects.all()
    if(request.GET.get('TestBut')):
        access_token = get_token(request.GET.get('code'))
        print("AT " + access_token)
        response  = requests.post('http://api.intra.42.fr/v2/me?access_token=' + access_token)
        if response.status_code == 200:
            status = response.json()
            print(json.dumps(status, sort_keys=True, indent=4))
            print(status['first_name'])
            print(status['last_name'])
            print(status['login'])
        repo_test(request.GET.get("git_url"), status['login'])
    return render(request, "repo.html", {"object": model})
 
def login_page(request):
    if(request.GET.get('Login')):
        url = 'https://api.intra.42.fr/oauth/authorize?client_id=' + str(CLIENT_ID)
        url += '&redirect_uri=http%3A%2F%2Flocalhost%3A8000%2F&response_type=code'
        return redirect(url)
 
# def token_page(request):
#     print('In token_page')
#     return render(request, "repo.html", {"object": model})
    # queryset = PushSwap.objects.all()
    # template_name = 'pushswap42/detail.html'
    # def get(self, request, *args, **kwargs):
    #     print("Search View get")
    #     query = request.GET.get("q")
    #     qs = None
    #     if query:
    #         qs = User.objects.filter(
    #             Q(username__icontains=query)
    #             )
    #     context = {"users": qs}
    #     return render(request, "search.html", context)