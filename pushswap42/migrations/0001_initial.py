# -*- coding: utf-8 -*-
# Generated by Django 1.10.5 on 2017-07-26 05:12
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Executable',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=25)),
                ('t_min_500', models.IntegerField()),
                ('t_max_500', models.IntegerField()),
                ('t_avg_500', models.IntegerField()),
            ],
        ),
    ]
